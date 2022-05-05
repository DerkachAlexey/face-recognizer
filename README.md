# face-recognizer
Application to recognize faces

# Requirements

* **OpenCV**  2.4
* **LevelDB**
* **CMake** 3.15

Also this project uses **spdlog** and **argparse** as git submodules

# Getting the Source

```bash
git clone --recurse-submodules https://github.com/DerkachAlexey/face-recognizer.git
```

# Building

## Build for Linux

```bash
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
```
# Usage Guide

## Optional arguments:
* -h --help       shows help message and exits [default: false]
* -v --version    prints version information and exits [default: false]
* --mode          specify the mode of application (registration, removal, recognition) [required]
* --name          name is required parameter for registration and removal modes. Specify the name of the person to register/remove

## Example of registration

```bash
face-recognizer --mode registration --name Oleksii
```
## Example of recognition

```bash
face-recognizer --mode recognition
```
## Example of removal from database

```bash
face-recognizer --mode removal --name Oleksii
```

**NOTATION**: for now application uses only web camera

# Files location

* Files of the LevelDB database: ~/.config/FaceRecognition/faceRecDB
* Files of logs: ~/.config/FaceRecognition/logs
* Files of people folders with photos: ~/.config/FaceRecognition/photosDatabase
* Necessary files for algorithms: /usr/local/share/data

# TODO

* Add config for application settings
* Save FaceRecognition model after person registration to remove
redundant model training
* (Probably) implement GUI part
