/*
 * IoT Server
 * 
 * This Node.js application handles and stores data from an IoT emulator.
 * It provides REST API endpoints for starting/stopping the emulator, retrieving emulator status,
 * and fetching the latest temperature and humidity data.
 * 
 * Author: Your Name
 * Date: Your Date
 */

const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors'); // Import the cors package

const app = express();
const port = 3000;

// Variable to track the state of the emulator (running or not)
let emulatorRunning = false;

// Variable to store the latest temperature and humidity data
let latestData = {
    temperature: null,
    humidity: null,
    timestamp: null
};

// Array to store all received data
let dataStore = [];

app.use(cors()); // Enable CORS for all routes
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Endpoint to start the emulator
app.post('/start', (req, res) => {
    emulatorRunning = true;
    res.json({ message: 'Emulator started.' });
});

// Endpoint to stop the emulator
app.post('/stop', (req, res) => {
    emulatorRunning = false;
    res.json({ message: 'Emulator stopped.' });
});

// Endpoint to get the emulator status
app.get('/status', (req, res) => {
    res.json({ running: emulatorRunning });
});

// Endpoint to receive data from the emulator
app.post('/data', (req, res) => {
    const { temperature, humidity } = req.body;
    if (emulatorRunning) {
        const timestamp = new Date();
        // Update the latest data
        latestData = {
            temperature,
            humidity,
            timestamp
        };
        // Store the received data in the dataStore array
        dataStore.push({ temperature, humidity, timestamp });
        res.json({ message: 'Data received.' });
    } else {
        res.status(400).json({ message: 'Emulator is not running.' });
    }
});

// Endpoint to fetch the latest data
app.get('/latest', (req, res) => {
    res.json(latestData);
});

// Endpoint to fetch all stored data
app.get('/data', (req, res) => {
    res.json(dataStore);
});

// Start the server and listen on the specified port
app.listen(port, () => {
    console.log(`IoT server is running on http://localhost:${port}`);
});