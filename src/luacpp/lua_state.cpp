/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** lua_state
*/

#include "luacpp/lua_state.h"
#include "luacpp/lua_table.h"
#include "luacpp/lua_function.h"

namespace luacpp {

static inline void DummyDeleter(lua_State*)
{}

LuaState::LuaState(LuaState&& rhs)
{
    m_l = rhs.m_l;
    m_deleter = rhs.m_deleter;
    m_gc_table_ref = rhs.m_gc_table_ref;

    rhs.m_l = nullptr;
    rhs.m_deleter = DummyDeleter;
    rhs.m_gc_table_ref = LUA_REFNIL;
}

LuaState& LuaState::operator=(LuaState&& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    if (m_l)
    {
        m_deleter(m_l);
    }

    m_l = rhs.m_l;
    m_deleter = rhs.m_deleter;
    m_gc_table_ref = rhs.m_gc_table_ref;

    rhs.m_l = nullptr;
    rhs.m_deleter = DummyDeleter;
    rhs.m_gc_table_ref = LUA_REFNIL;

    return *this;
}

static inline int CreateGcTable(lua_State* l)
{
    lua_createtable(l, 0, 1);
    lua_pushcfunction(l, luacpp_generic_destructor<DestructorObject>);
    lua_setfield(l, -2, "__gc");
    return luaL_ref(l, LUA_REGISTRYINDEX);
}

int LuaState::luacpp_index_for_class(lua_State* l)
{
    auto key = lua_tostring(l, 2);

    lua_getmetatable(l, 1);
    if (lua_isnil(l, -1))
    {
        return 1;
    }

    lua_getfield(l, -1, key);

    if (lua_isfunction(l, -1))
    {
        return 1;
    }

    if (lua_istable(l, -1))
    {
        lua_rawgeti(l, -1, MEMBER_GETTER_IDX);
        if (lua_isnil(l, -1))
        {
            luaL_error(l, "cannot read `%s`.", key);
            return 1;
        }

        lua_pushvalue(l, 1);
        lua_pushvalue(l, 2);
        lua_pcall(l, 2, 1, 0);

        return 1;
    }
    if (!lua_isnil(l, -1))
    {
        lua_pushnil(l);
        return 1;
    }
    lua_getiuservalue(l, 1, CLASS_PARENT_TABLE_IDX);

    lua_pushnil(l);
    while (lua_next(l, -2) != 0)
    {
        lua_getfield(l, -1, key);
        if (!lua_isnil(l, -1))
        {
            return 1;
        }

        lua_pop(l, 2);
    }

    lua_pushnil(l);
    return 1;
}

int LuaState::luacpp_newindex_for_class(lua_State* l)
{
    auto key = lua_tostring(l, 2);

    lua_getmetatable(l, 1);
    if (lua_isnil(l, -1))
    {
        luaL_error(l, "cannot find metatable of class.");
        return 0;
    }

    lua_getfield(l, -1, key);

    if (lua_istable(l, -1))
    {
        lua_rawgeti(l, -1, MEMBER_SETTER_IDX);
        if (lua_isnil(l, -1))
        {
            luaL_error(l, "cannot write `%s`.", key);
            return 0;
        }
        if (!lua_isfunction(l, -1))
        {
            luaL_error(l, "`setter` is not a function.");
            return 0;
        }
        lua_pushvalue(l, 1);
        lua_pushvalue(l, 3);
        lua_pcall(l, 2, 0, 0);
        return 0;
    }

    lua_getiuservalue(l, 1, CLASS_PARENT_TABLE_IDX);
    lua_pushnil(l);
    while (lua_next(l, -2) != 0)
    {
        lua_getfield(l, -1, key);
        if (!lua_isnil(l, -1))
        {
            lua_pushvalue(l, 3);
            lua_setfield(l, -3, key);
            return 0;
        }

        lua_pop(l, 2);
    }

    return 0;
}

int LuaState::luacpp_index_for_class_instance(lua_State* l)
{
    auto key = lua_tostring(l, 2);

    if (lua_gettop(l) == 2)
    {
        lua_getiuservalue(l, 1, 1);
    }
    lua_getiuservalue(l, -1, CLASS_INSTANCE_METATABLE_IDX);

    if (lua_isnil(l, -1))
    {
        return 1;
    }

    lua_getfield(l, -1, key);

    if (lua_isfunction(l, -1))
    {
        return 1;
    }

    if (lua_istable(l, -1))
    {
        lua_rawgeti(l, -1, MEMBER_GETTER_IDX);
        if (lua_isnil(l, -1))
        {
            luaL_error(l, "cannot read `%s`.", key);
            return 1;
        }

        lua_pushvalue(l, 1);
        lua_pushvalue(l, 2);
        lua_pcall(l, 2, 1, 0);
        return 1;
    }

    if (!lua_isnil(l, -1))
    {
        lua_pushnil(l);
        return 1;
    }

    lua_pop(l, 2);

    lua_getmetatable(l, -1);

    lua_getfield(l, -1, key);
    if (!lua_isnil(l, -1))
        return 1;
    lua_pop(l, 2);
    lua_getiuservalue(l, -1, CLASS_PARENT_TABLE_IDX);
    lua_pushnil(l);
    while (lua_next(l, -2) != 0)
    {
        lua_getiuservalue(l, -1, CLASS_INSTANCE_METATABLE_IDX);
        lua_getfield(l, -1, "__index");
        if (lua_isfunction(l, -1))
        {
            lua_pushvalue(l, 1);
            lua_pushvalue(l, 2);
            lua_pushvalue(l, -5);
            lua_pcall(l, 3, 1, 0);
            if (!lua_isnil(l, -1))
            {
                return 1;
            }
        }
        else
        {
            lua_getfield(l, -1, key);
            if (!lua_isnil(l, -1))
            {
                return 1;
            }
        }
        lua_pop(l, 3);
    }
    lua_pushnil(l);
    return 1;
}

int LuaState::luacpp_newindex_for_class_instance(lua_State* l)
{
    auto key = lua_tostring(l, 2);

    if (lua_gettop(l) == 3)
    {
        lua_getiuservalue(l, 1, 1);
    }

    lua_getiuservalue(l, -1, CLASS_INSTANCE_METATABLE_IDX);

    if (lua_isnil(l, -1))
    {
        luaL_error(l, "cannot find metatable of class instances.");
        return 0;
    }

    lua_getfield(l, -1, key);

    if (lua_istable(l, -1))
    {
        lua_rawgeti(l, -1, MEMBER_SETTER_IDX);
        if (lua_isnil(l, -1))
        {
            luaL_error(l, "cannot write `%s`.", key);
            return 0;
        }
        if (!lua_isfunction(l, -1))
        {
            luaL_error(l, "`setter` is not a function.");
            return 0;
        }
        lua_pushvalue(l, 1);
        lua_pushvalue(l, 3);
        lua_pcall(l, 2, 0, 0);
        return 0;
    }

    if (!lua_isnil(l, -1))
    {
        luaL_error(l, "`%s` is not a writable field exported by c++.", key);
        return 0;
    }

    lua_pop(l, 2);

    lua_getmetatable(l, -1);

    lua_getfield(l, -1, key);
    if (lua_istable(l, -1))
    {
        lua_rawgeti(l, -1, MEMBER_SETTER_IDX);
        if (lua_isnil(l, -1))
        {
            luaL_error(l, "cannot write `%s`.", key);
            return 0;
        }
        if (!lua_isfunction(l, -1))
        {
            luaL_error(l, "`setter` is not a function.");
            return 0;
        }
        lua_pushvalue(l, 1);
        lua_pushvalue(l, 3);
        lua_pcall(l, 2, 0, 0);
        return 0;
    }

    if (!lua_isnil(l, -1))
    {
        luaL_error(l, "`%s` is not a writable field exported by c++.", key);
        return 0;
    }

    lua_pop(l, 2);

    lua_getiuservalue(l, -1, CLASS_PARENT_TABLE_IDX);

    lua_pushnil(l);
    while (lua_next(l, -2) != 0)
    {

        lua_getiuservalue(l, -1, CLASS_INSTANCE_METATABLE_IDX);

        lua_getfield(l, -1, "__newindex");

        if (lua_isfunction(l, -1))
        {
            lua_pushvalue(l, 1);
            lua_pushvalue(l, 2);
            lua_pushvalue(l, 3);
            lua_pushvalue(l, -6);
            lua_pcall(l, 4, 0, 0);
            return 0;
        }
    }

    return 0;
}

void LuaState::CreateClassMetatable(lua_State* l)
{
    lua_createtable(l, 0, 2);

    lua_pushcfunction(l, luacpp_newindex_for_class);
    lua_setfield(l, -2, "__newindex");

    lua_pushcfunction(l, luacpp_index_for_class);
    lua_setfield(l, -2, "__index");
}

void LuaState::CreateClassInstanceMetatable(lua_State* l, int (*gc)(lua_State*))
{
    lua_createtable(l, 0, 3);

    lua_pushcfunction(l, luacpp_newindex_for_class_instance);
    lua_setfield(l, -2, "__newindex");

    lua_pushcfunction(l, luacpp_index_for_class_instance);
    lua_setfield(l, -2, "__index");

    lua_pushcfunction(l, gc);
    lua_setfield(l, -2, "__gc");
}

LuaState::LuaState(lua_State* l, bool is_owner)
{
    m_l = l;
    if (is_owner)
    {
        luaL_openlibs(l);
        m_deleter = lua_close;
    } else {
        m_deleter = DummyDeleter;
    }

    m_gc_table_ref = CreateGcTable(l);
}

LuaState::~LuaState()
{
    if (m_l)
    {
        luaL_unref(m_l, LUA_REGISTRYINDEX, m_gc_table_ref);
        m_deleter(m_l);
    }
}

void LuaState::Set(const char *name, const LuaRefObject& lobj)
{
    PushValue(m_l, lobj);
    lua_setglobal(m_l, name);
}

const char *LuaState::GetString(const char *name) const {
    lua_getglobal(m_l, name);
    const char *str = lua_tostring(m_l, -1);
    lua_pop(m_l, 1);
    return str;
}

LuaStringRef LuaState::GetStringRef(const char *name) const {
    lua_getglobal(m_l, name);
    size_t len = 0;
    const char *str = lua_tolstring(m_l, -1, &len);
    lua_pop(m_l, 1);
    return LuaStringRef(str, len);
}

lua_Number LuaState::GetNumber(const char *name) const {
    lua_getglobal(m_l, name);
    auto value = lua_tonumber(m_l, -1);
    lua_pop(m_l, 1);
    return value;
}

lua_Integer LuaState::GetInteger(const char *name) const {
    lua_getglobal(m_l, name);
    auto value = lua_tointeger(m_l, -1);
    lua_pop(m_l, 1);
    return value;
}

void* LuaState::GetPointer(const char *name) const {
    lua_getglobal(m_l, name);
    auto ptr = lua_touserdata(m_l, -1);
    lua_pop(m_l, 1);
    return ptr;
}

LuaObject LuaState::CreateString(const char *str, const char *name)
{
    lua_pushstring(m_l, str);
    LuaObject ret(m_l, -1);
    if (name)
    {
        lua_setglobal(m_l, name);
    } else {
        lua_pop(m_l, 1);
    }
    return ret;
}

LuaObject LuaState::CreateString(const char *str, uint64_t len, const char *name)
{
    lua_pushlstring(m_l, str, len);
    LuaObject ret(m_l, -1);
    if (name)
    {
        lua_setglobal(m_l, name);
    } else {
        lua_pop(m_l, 1);
    }
    return ret;
}

LuaObject LuaState::CreateNumber(lua_Number value, const char *name)
{
    lua_pushnumber(m_l, value);
    LuaObject ret(m_l, -1);
    if (name)
    {
        lua_setglobal(m_l, name);
    } else {
        lua_pop(m_l, 1);
    }
    return ret;
}

LuaObject LuaState::CreateInteger(lua_Integer value, const char *name)
{
    lua_pushinteger(m_l, value);
    LuaObject ret(m_l, -1);
    if (name)
    {
        lua_setglobal(m_l, name);
    } else {
        lua_pop(m_l, 1);
    }
    return ret;
}

LuaObject LuaState::CreatePointer(void* ptr, const char *name)
{
    lua_pushlightuserdata(m_l, ptr);
    LuaObject ret(m_l, -1);
    if (name)
    {
        lua_setglobal(m_l, name);
    } else {
        lua_pop(m_l, 1);
    }
    return ret;
}

LuaTable LuaState::CreateTable(const char *name)
{
    lua_newtable(m_l);
    LuaTable ret(m_l, -1);

    if (name)
    {
        lua_setglobal(m_l, name);
    }
    else
    {
        lua_pop(m_l, 1);
    }

    return ret;
}

bool LuaState::DoString(const char *chunk, std::string *errstr, const std::function<bool(uint32_t, const LuaObject&)>& callback)
{
    bool ok = (luaL_loadstring(m_l, chunk) == LUA_OK);
    if (!ok)
    {
        if (errstr)
        {
            *errstr = lua_tostring(m_l, -1);
        }
        lua_pop(m_l, 1);
        return false;
    }

    LuaFunction f(m_l, -1);
    ok = f.Execute(callback, errstr);
    lua_pop(m_l, 1);
    return ok;
}

bool LuaState::DoFile(const char *script, std::string *errstr, const std::function<bool(uint32_t, const LuaObject&)>& callback)
{
    bool ok = (luaL_loadfile(m_l, script) == LUA_OK);
    if (!ok)
    {
        if (errstr)
        {
            *errstr = lua_tostring(m_l, -1);
        }
        lua_pop(m_l, 1);
        return false;
    }

    LuaFunction f(m_l, -1);
    ok = f.Execute(callback, errstr);
    lua_pop(m_l, 1);
    return ok;
}

}
