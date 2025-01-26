# NIRBHAYA 🎯


## Basic Details
### Team Name: TECH TINKERS


### Team Members
- Member 1: Nandhana Manoj - NSS COLLEGE OF ENGINEERING, PALAKKAD
- Member 2: Nandana CM -  NSS COLLEGE OF ENGINEERING, PALAKKAD
- Member 3: Meenakshi A Dinesh -  NSS COLLEGE OF ENGINEERING, PALAKKAD

### Hosted Project Link
https://drive.google.com/drive/folders/1gicHbQ--KNQ5o_M-YAeXHEwYZwvf0NtR?usp=sharing

### Project Description
 "Nirbhaya" project addresses the growing safety concerns for women and children by leveraging technology to provide a reliable, real-time safety solution.
This project not only aims to solve a pressing issue but also aligns with our values of technological innovation and social responsibility.
The aim of the project "Nirbhaya" is to design and develop a prototype safety device integrated with advanced technologies to ensure the protection and security of women and children in distress situations.
This prototype focuses on demonstrating the feasibility and functionality of an affordable and portable safety device that can later be scaled into a market-ready solution to address the growing need for women and child safety.



### The Problem statement
Women, especially those who live alone, work late hours, or have medical conditions, face risks such as accidental falls, physical harassment, or other emergencies. Current safety solutions often rely on manual activation, which may not always be feasible during critical situations.Personal safety for Women, workplace safety, Child safety, Safety for hikers and solo travelers.

### The Solution
By this system we can Empower Safety,Enable Freedom - A Gaurdian of Hope and Security for Women & Children.This system enhances personal safety, reduces response time during emergencies, and promotes a sense of security for vulnerable populations in various scenarios. Its cost-effective and user-friendly design makes it a practical solution for widespread use.

## Technical Details
### Technologies/Components Used
For Software:
- Languages used  : C++(Arduino programming language),AT Commands(GSM Communication),NMEA protocol(GPS Data)
- Frameworks used : Embedded Systems Framework, IoT Framework, Agile Development, Signal Processing Framework.
- Libraries used  : MPU6050 Library, TinyGPS Library, SoftwareSerial Library, Wire Library.
- Tools used      : Hardware tools, Software tools,Protoping tools, Testing tools.

For Hardware:
- MPU-6050                   : For fall detection and orientation analysis.
- ARDUINO NANO               : As the microcontroller to process sensor data.
- GSM Module (SIM 800L)      : To sent SMS alerts with location.
- GPS NEO 6M Module          : To retrieve real-time location.
- Buzzer                     : For audio alerts.
- Push button                : For manual SOS acivation.
- Bread board & Jumper wire  : For prototyping and testing connections.        
  
### Implementation
For Software:
# Installation
1.Install arduino : From Arduino official website
2.Install required libraries  : Open Arduino IDE.
                                Go to Sketch > Include Library > Manage Libraries.
                                Search for the required libraries and click Install.
3.Upload Code to Arduino Nano : Connect the Arduino Nano to your computer via USB
                                Open the project code in Arduino IDE.
                                Select the correct Board and Port.
                                    Go to Tools > Board > Arduino Nano.
                                    Go to Tools > Port > COM (Port connected to Arduino).

# Run
After uploading the code : Power the Arduino Nano (via USB or external power source).
                           Open the Serial Monitor (Ctrl+Shift+M) in Arduino IDE to monitor sensor and GPS data
                           Ensure the GSM module is active and can send SMS.
                           
Verify GSM and GPS Modules : GSM Initialization Commands (Sent via Serial Monitor):
                                  Test network connection : AT
                                  Set SMS mode to text    : AT+CMGF=1
                                  Check signal strength   : AT+CSQ
                                  Send test SMS           : AT+CMGS="phone_number"
                                                            Message text here
                                                            (Press Ctrl+Z to send
                             GPS Data Validation:Check Serial Monitor for GPS coordinates or use debugging prints to ensure data is being received correctly.

### Project Documentation
For Software:

# Screenshots (Add at least 3)
![Screenshot1]![sc1](https://github.com/user-attachments/assets/4111887d-1266-4e9e-9c71-77392c65b3d9)
![Screenshot2]![sc2](https://github.com/user-attachments/assets/3f15d313-c837-4b28-a25c-d399a71dee40)
![Screenshot3]![sc3](https://github.com/user-attachments/assets/5ff548b4-dd22-46a9-bcc3-6d264296430e)
![Screenshot4]![sc4](https://github.com/user-attachments/assets/b57ec2ec-5b42-46cb-896b-eeb6911d7541)

The above mentioned four screenshot shows the working code as well as the respected output.


# Diagrams
![Workflow]![flowchart](https://github.com/user-attachments/assets/fff33160-24a7-4f7d-a518-a87417870f59)
Workflow Summary
1. Initialization:
The Arduino Nano initializes all components (MPU-6050, GPS, GSM, etc.) during startup.
2. Monitoring:
Continuously monitors the MPU-6050 for fall detection and the push button for manual SOS activation.
3. Action on Emergency:
Fall Detected/Manual Button Press:
Fetches location data from the GPS module.
Sends an alert SMS with the location using the GSM module.
Activates the buzzer to attract nearby attention.
4. Standby Mode:
Returns to monitoring after sending the alert, waiting for further input or events.


For Hardware:

# Schematic & Circuit
![Circuit]![ckt dia](https://github.com/user-attachments/assets/f28fec1e-2bc9-465c-979b-9020bca51503)

 1. Central Controller - Arduino Nano
 The Arduino Nano acts as the brain of the system, coordinating all components.It reads inputs from sensors and buttons, processes data, and controls output actions like sending alerts and activating the buzzer.
2. Inputs
Push Button:Used for manual SOS activation.
When pressed, it triggers the Arduino to send an alert SMS with GPS location to the predefined contacts.
MPU-6050:
A 6-axis motion-tracking sensor that includes an accelerometer and gyroscope.
Detects falls or abnormal movements by analyzing acceleration and orientation data.
Communicates with the Arduino via I2C protocol.
3. Outputs
Buzzer:
Provides an audible alarm to attract attention in case of an emergency.
Activated when the Arduino detects a fall or when the SOS button is pressed.
4. Communication Modules
SIM800L (GSM Module):
Responsible for sending SMS alerts to emergency contacts.
Controlled by the Arduino using AT commands through serial communication.
Neo-6M (GPS Module):
Provides real-time location coordinates (latitude and longitude).
The Arduino uses this data to include the user's location in the SMS alert.


![Schematic]
![flowchart](https://github.com/user-attachments/assets/42edb2d5-c664-4a05-b283-c6c8568e1a7e)


# Build Photos
![Team]![group](https://github.com/user-attachments/assets/8325531c-a9af-4500-9f1c-6b410020e2be) *GROUP TECH TINKERS*



![Components]
*List out all components shown*
![arduino nao](https://github.com/user-attachments/assets/9faf6f46-6eb9-4e30-b53a-53725cf9b0ae)
![neo 6m](https://github.com/user-attachments/assets/19a414b7-b678-49cd-ae20-a50d2fb976c3)
![mpu6050](https://github.com/user-attachments/assets/b1582060-fcf4-4fb9-9385-9c79a08a5bea)
![sim800l](https://github.com/user-attachments/assets/39818015-f8b9-45af-81f9-08d4a197ec2f)
![buzzer](https://github.com/user-attachments/assets/6bb6e9e9-9f2f-4944-b903-127eb8ef1af2)
![push button](https://github.com/user-attachments/assets/3f5d77a6-7c82-49df-8ca0-a40a3826303f)



![overall circuit](https://github.com/user-attachments/assets/47d4d214-a20d-4b9e-8a49-ba22327ff245)


![Final]
![final out circuit](https://github.com/user-attachments/assets/96a21a1c-ac18-429e-9454-4875cdc581be)
1. The system uses the GPS module to obtain location data.
2. The accelerometer detects falls or impacts and sends an interrupt signal to the microcontroller.
3. When a fall is detected or the push button is pressed, the microcontroller sends an SOS message with the location data to the emergency contact number via the GSM module.
4. The buzzer alerts the user in case of an emergency.



*Explain the final build*

### Project Demo
# Video
https://github.com/user-attachments/assets/82c23826-afc3-43d0-a40b-0d70dca3dd67
https://github.com/user-attachments/assets/4676362b-50c9-4962-afee-b1ec9911184a
https://github.com/user-attachments/assets/ad0777d7-7925-4420-ac37-cf6e671223ef

*When the push button is pressed alert sms and gps location  is sent to the corresponding phone number*
*When a fall or unexpected fall occurs "fall detected sms and gps location is sent to the corresponding phone number*

NIRBHAYA OVERVIEW
[NIRBHAYA.pdf](https://github.com/user-attachments/files/18549057/NIRBHAYA.pdf)



## Team Contributions
- NANDANA CM: HARDWARE,SOFTWARE
- NANDHANA MANOJ: HARDWARE,SOFTWARE
- MEENAKSHI A DINESH: HARDWARE,SOFTWARE

---
Made with ❤️ at TinkerHub
