import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'IoT Emulator Control',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  String status = 'Stopped';
  String temperature = '--';
  String humidity = '--';

  // Server URL
  final String serverUrl = 'http://localhost:3000';

  @override
  void initState() {
    super.initState();
    _getStatus();
    _getLatestData();
  }

  // Function to start the emulator
  Future<void> _startEmulator() async {
    final response = await http.post(Uri.parse('$serverUrl/start'));
    if (response.statusCode == 200) {
      setState(() {
        status = 'Running';
      });
    }
  }

  // Function to stop the emulator
  Future<void> _stopEmulator() async {
    final response = await http.post(Uri.parse('$serverUrl/stop'));
    if (response.statusCode == 200) {
      setState(() {
        status = 'Stopped';
      });
    }
  }

  // Function to get emulator status
  Future<void> _getStatus() async {
    final response = await http.get(Uri.parse('$serverUrl/status'));
    if (response.statusCode == 200) {
      final data = json.decode(response.body);
      setState(() {
        status = data['running'] ? 'Running' : 'Stopped';
      });
    }
  }

  // Function to get the latest data
  Future<void> _getLatestData() async {
    final response = await http.get(Uri.parse('$serverUrl/latest'));
   
    if (response.statusCode == 200) {
      final data = json.decode(response.body);  
      setState(() {
        temperature = data['temperature'] != null ? '${data['temperature']}°C' : '--';
        
        humidity = data['humidity'] != null ? '${data['humidity']}%' : '--';
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('IoT Emulator Control'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'Current Status: $status',
              style: TextStyle(
                fontSize: 24.0,
                fontWeight: FontWeight.bold,
              ),
            ),
            SizedBox(height: 20),
            Text(
              'Temperature: $temperature',
              style: TextStyle(
                fontSize: 20.0,
                fontWeight: FontWeight.normal,
              ),
            ),
            Text(
              'Humidity: $humidity',
              style: TextStyle(
                fontSize: 20.0,
                fontWeight: FontWeight.normal,
              ),
            ),
            SizedBox(height: 20),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                ElevatedButton(
                  onPressed: () {
                    _startEmulator();
                    _getStatus();
                  },
                  child: Text('Start Emulator'),
                ),
                SizedBox(width: 20),
                ElevatedButton(
                  onPressed: () {
                    _stopEmulator();
                    _getStatus();
                  },
                  child: Text('Stop Emulator'),
                ),
              ],
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _getLatestData,
              child: Text('Refresh Data'),
            ),
          ],
        ),
      ),
    );
  }
}
