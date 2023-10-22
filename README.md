![Logo](logo.png)

A lightweight serialization library for C++ projects.

[![C/C++ CI](https://github.com/Conor-McDonagh-Rollo/SerializeDat/actions/workflows/c-cpp.yml/badge.svg?branch=main)](https://github.com/Conor-McDonagh-Rollo/SerializeDat/actions/workflows/c-cpp.yml)

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Serialize and deserialize various data types including integers, strings, booleans, and custom structures.
- Flexible data structure allowing for easy extension and modification.
- Efficient and straightforward usage.

## Installation

1. Clone the repository:
	```sh
		git clone https://github.com/Conor-McDonagh-Rollo/SerializeDat.git
	```
2. Navigate to the project directory:
	```sh
		cd Path/To/SerializeDat
	```
3. Add the header file into your project:
	```sh
		cd SerializeDat/include
		cp ./SerializeDat.h ../Path/To/Your/Project
	```
4. (Optional) Compile the test:
	```sh
		cd SeralizeDat
		./build.bat <--- WINDOWS
		make <--- LINUX
	```

## Usage
Here's a quick start guide on how to use SerializeDat:

1. Define your data:
	```cpp
		Data myData;
		myData.node = "exampleNode";
		myData.ints.push_back(42);
	```
2. Add to Serializer:
	```cpp
		SerializeDat serializer;
		serializer.Add(myData);
	```
3. Save to a .dat file:
	```cpp
		serializer.Save("path_to_file.dat");
	```
4. Load from a .dat file:
	```cpp
		serializer.Load("path_to_file.dat");
	```
5. Get your data:
	```cpp
		Data loadedData = serializer.GetData(0);
		std::cout << loadedData.node << std::endl;
	```

## Contributing

Thank you for taking an interest in `SerializeDat`.

### Please Note:

**Direct contributions to this repository are not currently accepted.**

I encourage developers to fork this project and adapt it to fit their needs. If you decide to do this, ensure that you comply with the license terms and provide appropriate attribution.

However, while direct pull requests to this repository won't be merged, we are always open to feedback and discussions in the Issues section.

### Questions or Feedback?

If you have questions, feedback, or suggestions, please feel free to open an issue to discuss them. We appreciate all input, even if direct code contributions aren't being accepted.

Thank you for your understanding.

## License

This project is licensed under the GNU General Public License v3.0 (GPLv3). For more details, please see the [LICENSE](LICENSE) file in this repository or visit [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).
