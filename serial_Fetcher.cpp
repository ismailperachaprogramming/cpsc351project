#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

void fetchWeather(const std::string& latitude, const std::string& longitude, int locationIndex) {
    std::string filename = "file" + std::to_string(locationIndex + 1) + ".json";
    std::string url = "https://api.open-meteo.com/v1/forecast?latitude=" + latitude + "&longitude=" + longitude + "&current_weather=True";

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execlp("/usr/bin/curl", "curl", "-o", filename.c_str(), url.c_str(), nullptr);
        perror("Exec failed");
        exit(1);
    } else {
        // Parent process
        wait(nullptr); // Wait for the child to finish before proceeding to the next location
    }
}

int main() {
    std::ifstream input_file("locations.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    std::string latitude, longitude;
    int locationIndex = 0;

    while (input_file >> latitude >> longitude) {
        fetchWeather(latitude, longitude, locationIndex);
        locationIndex++;
    }

    input_file.close();
    return 0;
}

