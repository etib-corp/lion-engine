#pragma once

#include <cstdint>
#include <string>
#include <map>
#include <memory>

#include "Message.hpp"

namespace LE
{
    /**
     * @class MessageBuilder
     * @brief A builder class to construct Message objects in a step-by-step manner.
     *
     * The MessageBuilder class provides methods to configure the parts of a Message object,
     * such as the ECS ID, topic ID, action, body, and reliability.
     */
    class MessageBuilder
    {
    public:
        /**
         * @brief Starts building a new Message object.
         */
        MessageBuilder() : message_(std::make_shared<Message>()) {}

        /**
         * @brief Sets the MagicNumber ID for the message.
         *
         * @param magicNumber The MagicNumber ID to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setMagicNumber(uint8_t magicNumber)
        {
            message_->setMagicNumber(magicNumber);
            return shared_from_this();
        }

        /**
         * @brief Sets the ECS ID (Emmiter ID) for the message.
         *
         * @param emmiter_id The ECS ID to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setEmmiterID(uint8_t emmiter_id)
        {
            message_->setEmmiterID(emmiter_id);
            return shared_from_this();
        }

        /**
         * @brief Sets the receiver ID for the message.
         *
         * @param receiver_id The receiver ID to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setReceiverID(uint8_t receiver_id)
        {
            message_->setReceiverID(receiver_id);
            return shared_from_this();
        }

        /**
         * @brief Sets the topic ID for the message.
         *
         * @param topic_id The topic ID to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setTopicID(uint8_t topic_id)
        {
            message_->setTopicID(topic_id);
            return shared_from_this();
        }

        /**
         * @brief Sets the action for the message.
         *
         * @param action The action to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setAction(uint8_t action)
        {
            message_->setAction(action);
            return shared_from_this();
        }

        /**
         * @brief Sets the header for the message.
         *
         * @param header The header to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setHeader(const Header &header)
        {
            message_->setHeader(header);
            return shared_from_this();
        }

        /**
         * @brief Sets the body for the message.
         *
         * @param body The body to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setBody(const Body &body)
        {
            message_->setBody(body);
            return shared_from_this();
        }

        /**
         * @brief Sets the reliability flag for the message.
         *
         * @param is_reliable The reliability flag to be set.
         * @return Shared pointer to MessageBuilder for chaining.
         */
        std::shared_ptr<MessageBuilder> setReliable(bool is_reliable)
        {
            message_->setReliable(is_reliable);
            return shared_from_this();
        }

        /**
         * @brief Finalizes the building process and returns the constructed Message object.
         *
         * @return A shared pointer to the constructed Message object.
         */
        std::shared_ptr<Message> build()
        {
            return message_;
        }

    private:
        std::shared_ptr<Message> message_; ///< The Message instance being constructed.
    };
} // namespace LE
