int touchRead_pin0 = 0;
int touchRead_pin1 = 1;
int touchRead_pin2 = 23;
int touchRead_pin3 = 22;

int data0;
int data1;
int data2;
int data3;

int counter0 = 0;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;

const int numReadings = 10;

// SENSOR 0 RUNNING AVG SETUP //
int readings0[numReadings];      // the readings from the analog input
int readIndex0 = 0;              // the index of the current reading
int total0 = 0;                  // the running total
int average0 = 0;                // the average

// SENSOR 1 RUNNING AVG SETUP //

int readings1[numReadings];      // the readings from the analog input
int readIndex1 = 0;              // the index of the current reading
int total1 = 0;                  // the running total
int average1 = 0;                // the average

// SENSOR 2 RUNNING AVG SETUP //

int readings2[numReadings];      // the readings from the analog input
int readIndex2 = 0;              // the index of the current reading
int total2 = 0;                  // the running total
int average2 = 0;                // the average

// SENSOR 3 RUNNING AVG SETUP //

int readings3[numReadings];      // the readings from the analog input
int readIndex3 = 0;              // the index of the current reading
int total3 = 0;                  // the running total
int average3 = 0;                // the average

float difference0 = 0;
float difference1 = 0;
float difference2 = 0;
float difference3 = 0;

float diffpercent0 = 0;
float diffpercent1 = 0;
float diffpercent2 = 0;
float diffpercent3 = 0;

void setup() {
  Serial.begin(9600);

// SENSOR 0 SETUP

  for (int thisReading0 = 0; thisReading0 < numReadings; thisReading0++) {
    readings0[thisReading0] = 0;
  }

// SENSOR 1 SETUP 

  for (int thisReading1 = 0; thisReading1 < numReadings; thisReading1++) {
    readings1[thisReading1] = 0;
  }

// SENSOR 2 SETUP 

  for (int thisReading2 = 0; thisReading2 < numReadings; thisReading2++) {
    readings2[thisReading2] = 0;
  }

// SENSOR 3 SETUP 

  for (int thisReading3 = 0; thisReading3 < numReadings; thisReading3++) {
    readings3[thisReading3] = 0;
  }
}

void loop() {
  data0 = touchRead(touchRead_pin0);
  data1 = touchRead(touchRead_pin1);
  data2 = touchRead(touchRead_pin2);
  data3 = touchRead(touchRead_pin3);


// CALCULATE RUNNING AVG FOR SENSOR 0//

    // subtract the last reading:
  total0 = total0 - readings0[readIndex0];
  // read from the sensor:
  readings0[readIndex0] = data0;
  // add the reading to the total:
  total0 = total0 + readings0[readIndex0];
  // advance to the next position in the array:
  readIndex0 = readIndex0 + 1;

  // if we're at the end of the array...
  if (readIndex0 >= numReadings) {
    // ...wrap around to the beginning:
    readIndex0 = 0;
  }

  // calculate the average:
  average0 = total0 / numReadings;
  // send it to the computer as ASCII digits
//  Serial.println(average0);
//  delay(1);        // delay in between reads for stability


// CALCULATE RUNNING AVG FOR SENSOR 1//

    // subtract the last reading:
  total1 = total1 - readings1[readIndex1];
  // read from the sensor:
  readings1[readIndex1] = data1;
  // add the reading to the total:
  total1 = total1 + readings1[readIndex1];
  // advance to the next position in the array:
  readIndex1 = readIndex1 + 1;

  // if we're at the end of the array...
  if (readIndex1 >= numReadings) {
    // ...wrap around to the beginning:
    readIndex1 = 0;
  }

  // calculate the average:
  average1 = total1 / numReadings;
  // send it to the computer as ASCII digits
//  Serial.println(average1);
//  delay(1);        // delay in between reads for stability

// CALCULATE RUNNING AVG FOR SENSOR 2//

    // subtract the last reading:
  total2 = total2 - readings2[readIndex1];
  // read from the sensor:
  readings2[readIndex2] = data2;
  // add the reading to the total:
  total2 = total2 + readings2[readIndex2];
  // advance to the next position in the array:
  readIndex2 = readIndex2 + 1;

  // if we're at the end of the array...
  if (readIndex2 >= numReadings) {
    // ...wrap around to the beginning:
    readIndex2 = 0;
  }

  // calculate the average:
  average2 = total2 / numReadings;
  // send it to the computer as ASCII digits
//  Serial.println(average1);
//  delay(1);        // delay in between reads for stability

// CALCULATE RUNNING AVG FOR SENSOR 3//

    // subtract the last reading:
  total3 = total3 - readings3[readIndex1];
  // read from the sensor:
  readings3[readIndex3] = data3;
  // add the reading to the total:
  total3 = total3 + readings3[readIndex3];
  // advance to the next position in the array:
  readIndex3 = readIndex3 + 1;

  // if we're at the end of the array...
  if (readIndex3 >= numReadings) {
    // ...wrap around to the beginning:
    readIndex3 = 0;
  }

  // calculate the average:
  average3 = total3 / numReadings;
  // send it to the computer as ASCII digits
//  Serial.println(average1);
//  delay(1);        // delay in between reads for stability

difference0 = data0-average0;
difference1 = data1-average1;
difference2 = data2-average2;
difference3 = data3-average3;

diffpercent0 = (difference0/data0)*100;
diffpercent1 = (difference1/data1)*100;
diffpercent2 = (difference2/data2)*100;
diffpercent3 = (difference3/data3)*100;


  if (diffpercent0 > 6) {
//    counter0++;
    playmidi0();
  }

  if (diffpercent1 > 6) {
//    counter1++;
    playmidi1();
  }

  if (diffpercent0 > 6) {
//    counter2++;
    playmidi2();
  }

  if (diffpercent1 > 6) {
//    counter3++;
    playmidi3();
  }


  Serial.print("sensor0: ");  
  Serial.print(diffpercent0);
  Serial.print("sensor1: ");
  Serial.print(diffpercent1);
  Serial.print("sensor2: ") ;
  Serial.print(diffpercent2);
  Serial.print("sensor3: ");
  Serial.println(diffpercent3); 
//
  delay(100);
}

void playmidi0 () {
//  if (counter0 % 2 == 0) {
//    usbMIDI.sendNoteOn (51, 40, 1);
    usbMIDI.sendNoteOn (53, 40, 1);
//    usbMIDI.sendNoteOn (57, 40, 1);
//  }
}

void playmidi1 () {
//  if (counter1 % 2 == 0) {
//    usbMIDI.sendNoteOn (70, 40, 1);
    usbMIDI.sendNoteOn (57, 40, 1);
//    usbMIDI.sendNoteOn (50, 40, 1);
//  }
}

void playmidi2 () {
//  if (counter2 % 2 == 0) {
//    usbMIDI.sendNoteOn (67, 40, 1);
    usbMIDI.sendNoteOn (51, 40, 1);
//    usbMIDI.sendNoteOn (74, 40, 1);

//  }
}

void playmidi3 () {
//  if (counter3 % 2 == 0) {
////    usbMIDI.sendNoteOn (38, 40, 1);
    usbMIDI.sendNoteOn (38, 40, 1);
//    usbMIDI.sendNoteOn (26, 40, 1); 
//  } 
}
