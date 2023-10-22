#include <SerializeDat.h>

bool TestLoadAndSave() {
    Serialize data;

    // Test data
    Data testdata;
    testdata.node = "TestNode";
    testdata.vector2s.push_back(Vec2(10, 10));
	std::cout << "Test data initialized." << std::endl;

    // Save test data to a file
    data.Add(testdata);
    data.Save("test_simple.dat");
	std::cout << "Test data added and saved." << std::endl;

    // Clear the data buffer
    data.Clear();
	std::cout << "Data cleared." << std::endl;

    // Load the saved data from the file
    data.Load("test_simple.dat");
	std::cout << "Data loaded. Size: " << data.Size() << std::endl;

    // Verify that the loaded data matches the test data
    if (data.Size() == 1) {
        Data loadedData = data.GetData(0);
		std::cout << "Get loaded data 0. Size: " << loadedData.vector2s.size() << ", X: " << loadedData.vector2s[0].x << ", Y: " << loadedData.vector2s[0].y << std::endl;

        if (loadedData.node == "TestNode" && loadedData.vector2s.size() == 1 &&
            loadedData.vector2s[0].x == 10 && loadedData.vector2s[0].y == 10) {
            return true; // Test passed
        }
    }

    return false; // Test failed
}

int main() {
    // Run the test
    bool testResult = TestLoadAndSave();

    if (testResult) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}