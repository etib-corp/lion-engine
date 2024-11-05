# Lion engine built-in sound system

The Lion engine has a built-in sound system that allows you to play sounds in your game. The sound system is based on the [OpenAL](https://www.openal.org/) library.

## Sound files format

The Lion engine supports the following sound file formats:
- WAV
- MP3

## How does it works ?

At initialization, lion creates a `Device` object that represents the sound device. This object is created when the engine is initialized and destroyed when the engine is closed.
- The `Device` object is used to create an `OpenAL` context.
- It is not accessible from the user, but it is used internally by the engine. (Maybe in the future, it will be accessible to the user in case he wants to use it).

All you have to do is in the next part of the documentation.

## How to load a sound file ?

To load a sound file, you must use the `Sound` class. The `Sound` class is used to load a sound file and you can do the following operations:
- Play
- Pause
- Stop
- Replay

Here is an example of how to load a sound file:

```cpp
#include "Sound/Sound.hpp"

int main()
{
    LE::Sound::Sound *sound = new LE::Sound::Sound("path/to/sound/file.mp3");
    // ...
}
```

To play a sound, you must use the `play` method of the `Sound` class. Here is an example of how to play a sound:

```cpp
#include "Sound/Sound.hpp"

int main()
{
    LE::Sound::Sound *sound = new LE::Sound::Sound("path/to/sound/file.mp3");
    sound.play();
}
```

If you want to load a `WAV` file, you have to specify it like this:

```cpp
#include "Sound/Sound.hpp"

int main()
{
    LE::Sound::Sound *sound = new LE::Sound::Sound("path/to/sound/file.wav", LE::Sound::FileType::WAV);
    sound.play();
}
```

To pause a sound, you must use the `pause` method of the `Sound` class. Here is an example of how to pause a sound:

```cpp
#include "Sound/Sound.hpp"

int main()
{
    LE::Sound::Sound *sound = new LE::Sound::Sound("path/to/sound/file.mp3");
    sound.play();
    sound.pause();
}
```

To stop a sound, you must use the `stop` method of the `Sound` class. Here is an example of how to stop a sound:

```cpp
#include "Sound/Sound.hpp"

int main()
{
    LE::Sound::Sound *sound = new LE::Sound::Sound("path/to/sound/file.mp3");
    sound.play();
    sound.stop();
}
```

To replay a sound, you must use the `replay` method of the `Sound` class. Here is an example of how to replay a sound:

```cpp
#include "Sound/Sound.hpp"

int main()
{
    LE::Sound::Sound *sound = new LE::Sound::Sound("path/to/sound/file.mp3");
    sound.play();
    sound.replay();
}
```

> **!!! Warning !!!**:
>   - You must have to initialize the engine before using the sound system. If you don't >      do that, the sound system will not work.
>  - You must have to load your sound in the RAM, because it calls a thread and it will >      not work if the sound is not loaded in the RAM.


## Additionnal features

### Playlist

The Lion engine has a built-in playlist system that allows you to play a list of sounds. To use the playlist system, you must use the `Playlist` class. The `Playlist` class is used to load a list of sounds and you can do the following operations:
- Play
- Pause
- Stop
- Replay

When you create your playlist, you just only give a path to a directory containing your sound files. The `Playlist` class will load all the sound files in the directory and you can play them.

Here is an example of how to use the playlist system:

```cpp
#include "Sound/Playlist.hpp"

int main()
{
    LE::Sound::Playlist *playlist = new LE::Sound::Playlist("path/to/directory/containing/sound/files");
    playlist.play();
}
```