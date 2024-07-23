/*
 * IoT Emulator Application
 * 
 * This C++ application simulates an IoT device that sends temperature and humidity data to a server every 5 seconds.
 * 
 * Features:
 * - Simulate temperature (-10 to 50°C) and humidity (0 to 100%) data.
 * - Send data to a server every 5 seconds.
 * - Implement start, stop, and status functionalities.
 * 
 * Author: Anish
 * Date: 23.07.2024
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <atomic>
#include <chrono>
#include <curl/curl.h> // Assuming you have libcurl installed for sending HTTP requests

using namespace std;

// Atomic variables to control the state of the emulator
atomic<bool> running(false);
atomic<bool> stopRequested(false);
thread emulationThread;

// Function to send data to the server using libcurl
void sendDataToServer(float temperature, float humidity) {
    
    const string url = "http://localhost:3000/data"; //Modify the emulator code to send data to IoT Server
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        string postFields = "temperature=" + to_string(temperature) + "&humidity=" + to_string(humidity);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }
}

// Function to generate random temperature and humidity data and send it to the server
void generateAndSendData() {
    srand(time(0)); // Seed for random number generation
    while (running) {
        float temperature = -10 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (50 - (-10))));
        float humidity = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 100);

        // Print the values of temperature and humidity to the console
        //cout << "Temperature: " << temperature << "°C, Humidity: " << humidity << "%" << endl;

        sendDataToServer(temperature, humidity);
        this_thread::sleep_for(chrono::seconds(5));

        if (stopRequested) {
            running = false;
        }
    }
}

// Function to start the emulator
void startEmulator() {
    if (!running) {
        running = true;
        stopRequested = false;
        emulationThread = thread(generateAndSendData);
        cout << "Emulator started." << endl;
    } else {
        cout << "Emulator is already running." << endl;
    }
}

// Function to stop the emulator
void stopEmulator() {
    if (running) {
        stopRequested = true;
        emulationThread.join(); // Wait for the thread to finish
        cout << "Emulator stopped." << endl;
    } else {
        cout << "Emulator is not running." << endl;
    }
}

// Function to display the status of the emulator
void statusEmulator() {
    if (running) {
        cout << "Emulator is running." << endl;
    } else {
        cout << "Emulator is stopped." << endl;
    }
}

// Main function to handle user input and control the emulator
int main() {
    char command;
    cout << "Enter 's' to start, 't' to stop, 'u' to get status, 'q' to quit:" << endl;
    while (true) {
        cin >> command;
        switch (command) {
            case 's':
                startEmulator();
                break;
            case 't':
                stopEmulator();
                break;
            case 'u':
                statusEmulator();
                break;
            case 'q':
                if (running) {
                    stopEmulator();
                }
                return 0;
            default:
                cout << "Invalid command. Enter 's' to start, 't' to stop, 'u' to get status, 'q' to quit:" << endl;
        }
    }
    return 0;
}
