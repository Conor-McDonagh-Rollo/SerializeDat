# SerializeDat
**A simple one line data serializer for simple data**
### How to use
Place the h and cpp files somewhere in your project and link them, then use accordingly:
```cpp
// How to use SerializeDat
#include <iostream>
#include <SerializeDat.h>

int main() {
	
	Serialize ser; // The serializer object
	ser.Load("data.dat"); // Could be an empty text file, if not it will fill the data buffer with the file's data
  
	Data newdata; // The data object we will add to the data buffer
	newdata.node = "Data1"; // This will be our key for finding this specific data node in the buffer later
  
	newdata.ints.push_back(12);
	newdata.strings.push_back("My favourite number");
  
	ser.Add(newdata); // This will add the data we just created to the buffer
	ser.Save("data.dat"); // The buffer is now serialized to the data file
  
  
	ser.Clear(); // Clears the buffer so we can load it again to prove it works
	ser.Load("data.dat"); // Loads our data we saved into our buffer
  
	Data saveddata = ser.GetData("Data1"); // Gets our data from the buffer
  
	std::cout << saveddata.strings[0] << " is " << saveddata.ints[0] << std::endl;
	// This will print "My favourite number is 12" if everything is working
  
  
	return 0;
  
}
```
