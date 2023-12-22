//Rhythm for easier access
enum NoteDuration {
  quarter = 200,   
  eighth = 100,   
  dottedEighth = 150,
  eighthTriplet = 66,
  sixteenth = 50, 
  half = 400,
  quarterRest = 200,
  eighthRest = 100, 
  sixteenthRest = 66, 
  halfRest = 400,      
  wholeRest = 800
};
//Turning MIDInotes into solfege for easier access - NOTE THAT A AND B ARE WRITTEN IN LOWERCASE
enum MidiNote {
  Cm5 = -48, Dbm5 = -47, Dm5 = -46, Ebm5 = -45, Em5 = -44, Fm5 = -43, Gbm5 = -42, Gm5 = -41, Abm5 = -40, Am5 = -39, Bbm5 = -38, Bm5 = -37,
  Cm4 = -36, Dbm4 = -35, Dm4 = -34, Ebm4 = -33, Em4 = -32, Fm4 = -31, Gbm4 = -30, Gm4 = -29, Abm4 = -28, Am4 = -27, Bbm4 = -26, Bm4 = -25,
  Cm3 = -24, Dbm3 = -23, Dm3 = -22, Ebm3 = -21, Em3 = -20, Fm3 = -19, Gbm3 = -18, Gm3 = -17, Abm3 = -16, Am3 = -15, Bbm3 = -14, Bm3 = -13,
  Cm2 = -12, Dbm2 = -11, Dm2 = -10, Ebm2 = -9, Em2 = -8, Fm2 = -7, Gbm2 = -6, Gm2 = -5, Abm2 = -4, Am2 = -3, Bbm2 = -2, Bm2 = -1,
  Cm1 = 0, Dbm1 = 1, Dm1=2, Ebm1= 3, Em1=4, Fm1=5, Gbm1=6, Gm1=7, Abm1=8, Am1=9, Bbm1=10, Bm1=11,
  C0 = 12, Db0=13, D0=14, Eb0=15, E0=16, F0=17, Gb0=18, G0=19, Ab0=20, a0 =21, Bb0=22, b0=23,
  C1 = 24, Db1=25, D1=26, Eb1=27, E1=28, F1=29, Gb1=30, G1=31, Ab1=32, a1=33, Bb1=34, b1=35,
  C2 = 36, Db2= 37, D2=38, Eb2=39, E2=40, F2=41, Gb2=42, G2=43, Ab2=44, a2=45, Bb2=46, b2=47,
  C3 = 48, Db3=49, D3=50, Eb3=51, E3=52, F3=53, Gb3=54, G3=55, Ab3=56, a3=57, Bb3=58, b3=59,
  C4 = 60, Db4=61, D4=62, Eb4=63, E4=64, F4=65, Gb4=66, G4=67, Ab4=68, a4=69, Bb4=70, b4=71,
  C5 = 72, Db5=73, D5=74, Eb5=75, E5=76, F5=77, Gb5=78, G5=79, Ab5=80, a5=81, Bb5=82, b5=83,
  C6 = 84, Db6=85, D6=86, Eb6=87, E6=88, F6=89, Gb6=90, G6=91, Ab6=92, a6=93, Bb6=94, b6=95,  
  C7 = 96, Db7=97, D7=98, Eb7=99, E7=100, F7=101, Gb7=102, G7=103, Ab7=104, a7=105, Bb7=106, b7=107
};

//Turning frequencies into Midi Numbers
float makeMIDI(int midiNote) {
    // Define the reference frequency for A4 (440 Hz)
    float referenceFrequency = 440.0;
    
    int note = midiNote % 12;
    int octave = (midiNote /12) - 1;

    // Calculate the number of half steps away from A4
    int halfSteps = note - 9 + octave * 12;
    
    // Calculate the frequency using the formula
    float frequency = referenceFrequency * pow(2.0, halfSteps / 12.0);
    
    return frequency;
}
//Setting a MIDI function
float MIDI;

//1&3
unsigned int notes1[] = {Am3, Am3, eighthRest, Am3, sixteenthRest, Am3, wholeRest};
unsigned int rhythms1[] = {quarter, quarter, eighthRest, eighth, sixteenthRest, dottedEighth, wholeRest};
//2&4
unsigned int notes2[] = {Bbm3, Bbm3, eighthRest, Bbm3, sixteenthRest, Bbm3, wholeRest};
unsigned int rhythms2[] = {eighth, quarter, eighth, eighth, quarter, eighth, eighth};
//3&5
unsigned int notes3[] = {Cm2, Cm2, eighthRest, Cm2, sixteenthRest, Cm2, wholeRest};
unsigned int rhythms3[] = {quarter, quarter, eighthRest, eighth, sixteenthRest, dottedEighth, wholeRest};
//4&6
unsigned int notes4[] = {Dm2, Dm2, eighthRest, Fm3, sixteenthRest, Gm3, wholeRest};
unsigned int rhythms4[] = {eighth, quarter, eighth, eighth, quarter, eighth, eighth};
//5&7
unsigned int notes5[] = {Am3, Am3, eighthRest, Cm3, sixteenthRest, Am3, wholeRest};
unsigned int rhythms5[] = {quarter, quarter, eighthRest, eighth, sixteenthRest, dottedEighth, wholeRest};
//6&8
unsigned int notes6[] = {Dbm2, Dbm2, eighthRest, Em3, sixteenthRest, Fm3, wholeRest};
unsigned int rhythms6[] = {eighth, quarter, eighth, eighth, quarter, eighth, eighth};
//7&9
unsigned int notes7[] = {Ebm2, Ebm2, eighthRest, Bm3, sixteenthRest, Dm3, wholeRest};
unsigned int rhythms7[] = {eighth, quarter, eighth, eighth, quarter, eighth, eighth};

//1&2&3
unsigned int arp1[] = {Am3, Em2, Am2, Em1, Am1, E0, A0, E1, A1, A2};
unsigned int beat1[] = {eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth,};
//2&3&4
unsigned int arp2[] = {Bbm3, Fm2, Bbm2, Fm1, Bbm1, F0, G0, Gb1, Bb1, Bb2};
unsigned int beat2[] = {eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth,};
//3&4&5
unsigned int arp3[] = {Bm3, Gbm2, Bm2, Gbm1, Bm1, E0, A0, Gb1, b1, b2};
unsigned int beat3[] = {eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth,};
//4&5&6
unsigned int arp4[] = {Cm2, Gbm2, Cm1, Gbm1, Fm1, Ebm1, A0, C0, Gb0};
unsigned int beat4[] = {eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth};
//5&6&7
unsigned int arp5[] = {D1, A0, Bb0, Db1, Ab0, Eb0, Abm1, Eb0, Ab0};
unsigned int beat5[] = {eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth};
//6&7&8
unsigned int arp6[] = {E1, A1, Eb1, A0, E0, Am1, Gm1, Bbm1, Ebm1};
unsigned int beat6[] = {eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth};
//7&8&9
unsigned int arp7[] = {E2, A1, E1, A0, E0, Am1, Em1, Am2, Em2};
unsigned int beat7[] = {eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth, eighth};


unsigned int* currentNotes;
unsigned int* currentRhythms;
int currentNoteIndex = -1;
unsigned long previousMillis = 0;
bool melodyPlaying = false;
//1&2&3&4&5-random(0,1000)
//define the pins nicknames
char bt1 = 2;  //button 1 is on pin 2
char bt2 = 3;  //button 2 is on pin 3
char bt3 = 4;  //button 3 is on pin 4
char bt4 = 5; //button 4 is on pin 5
char bt5 = 6; //button 5 is on pin 6
char bt6 = 7; //button 6 is on pin 7
char bt7 = 9; //button 7 is on pin 9
char bt8 = 10; //button 8 is on pin 10
char bt9 = 11; //button 9 is on pin 11
char SPKR = 12;    //Speaker is on pin 13
char led1 = 13;  //LED 1 is on pin 13


// the setup function runs once when you press reset or power the board
void setup() {
  //button inputs
  pinMode(bt1, INPUT); //button 1 is an Digital INPUT
  pinMode(bt2, INPUT); //button 2 is an Digital INPUT
  pinMode(bt3, INPUT); //button 3 is an Digital INPUT
  pinMode(bt4, INPUT); //button 4 is an Digital INPUT
  pinMode(bt5, INPUT); //button 5 is an Digital INPUT
  pinMode(bt6, INPUT); //button 6 is an Digital INPUT
  pinMode(bt7, INPUT); //button 7 is an Digital INPUT
  pinMode(bt8, INPUT); //button 8 is an Digital INPUT
  pinMode(bt9, INPUT); //button 9 is an Digital INPUT
  //LED out  
  pinMode(led1, OUTPUT);  //LED 1 is an Digital OUTPUT
}

// the loop function runs over and over again forever
void loop() {
  //Read the value of the button pins and store in variable
  char btn1 = digitalRead(bt1);  //btn1 will show HIGH when button 1 is pressed
                                //btn1 will show LOW when button 1 is not pressed
  char btn2 = digitalRead(bt2);  //btn2 will show HIGH when button 2 is pressed
                                //btn2 will show LOW when button 2 is not pressed
  char btn3 = digitalRead(bt3);  //btn3 will show HIGH when button 3 is pressed
                                //btn3 will show LOW when button 3 is not pressed
  char btn4 = digitalRead(bt4);
  char btn5 = digitalRead(bt5);
  char btn6 = digitalRead(bt6);
  char btn7 = digitalRead(bt7);
  char btn8 = digitalRead(bt8);
  char btn9 = digitalRead(bt9);

  //do some tests (conditionals) to see which combination of buttons is pressed
  //play tone on the speaker and turn on/off led's accordingly 
  //BUTTON 1
  if (btn1 == HIGH && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  {   
    tone(SPKR,Dbm1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW);
    delay(50);
  }
  //BUTTON 2
  else if (btn1 == LOW && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)   {
    tone(SPKR,Dm1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 3
   else if (btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)    {
    tone(SPKR,Ebm1); 
    digitalWrite(led1, HIGH);

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 4 
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR,Em1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 5 
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR,Fm1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 6
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR,Gbm1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW);
    delay(50);
  }
  //BUTTON 7
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == HIGH && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR,Gm1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 8
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == HIGH && btn9 == LOW) {  
    tone(SPKR,Abm1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 9
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == HIGH) {  
    tone(SPKR,Am1); 
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 1 & 2 Percussion1
  else if (btn1 == HIGH && btn2 == HIGH && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    tone(SPKR,random(0, 100));    
    digitalWrite(led1, HIGH); 
  }

  //BUTTON 2&3 Percussion2
  else if (btn1 == LOW  && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    tone(SPKR,random(100, 200));    
    digitalWrite(led1, HIGH); 
  }
  //BUTTON 3&4 Percussion3
  else if (btn1 == LOW  && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    tone(SPKR,random(200, 300));    
    digitalWrite(led1, HIGH); 
  }
  //BUTTON 4&5 Percussion 4
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    tone(SPKR,random(300, 400));    
    digitalWrite(led1, HIGH); 
  }
  //BUTTON 5&6 Percussion 5
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    tone(SPKR,random(400, 500));    
    digitalWrite(led1, HIGH); 
  }
  //BUTTON 6&7 Percussion 6
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH && btn7 == HIGH && btn8 == LOW && btn9 == LOW)  { 
    tone(SPKR,random(500, 600));    
    digitalWrite(led1, HIGH); 
  }
  //BUTTON 7&8 Percussion 7
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == HIGH && btn8 == HIGH && btn9 == LOW)  { 
    tone(SPKR,random(600, 700));    
    digitalWrite(led1, HIGH); 
  }
  //BUTTON 8&9 Percussion 8 
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == HIGH && btn9 == HIGH)  { 
    tone(SPKR,random(700, 800));    
    digitalWrite(led1, HIGH); 
  }
    //BUTTON 1 & 3
  else if (btn1 == HIGH  && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    playMelody(notes1, rhythms1, sizeof(notes1)/sizeof(notes1[0]));
  }
    //BUTTON 2 & 4
  else if (btn1 == LOW  && btn2 == HIGH && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    playMelody(notes2, rhythms2, sizeof(notes2)/sizeof(notes2[0]));
  }
    //BUTTON 3 & 5
  else if (btn1 == LOW  && btn2 == LOW && btn3 == HIGH && btn4 == LOW && btn5 == HIGH && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    playMelody(notes3, rhythms3, sizeof(notes3)/sizeof(notes3[0]));
  }
    //BUTTON 4 & 6
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == LOW && btn6 == HIGH && btn7 == LOW && btn8 == LOW && btn9 == LOW)  { 
    playMelody(notes4, rhythms4, sizeof(notes4)/sizeof(notes4[0]));
  }
    //BUTTON 5 & 7
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == LOW && btn7 == HIGH && btn8 == LOW && btn9 == LOW)  { 
    playMelody(notes5, rhythms5, sizeof(notes5)/sizeof(notes5[0]));
  }
    //BUTTON 6 & 8
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH && btn7 == LOW && btn8 == HIGH && btn9 == LOW)  { 
    playMelody(notes6, rhythms6, sizeof(notes6)/sizeof(notes6[0]));
  }
    //BUTTON 7 & 9
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == HIGH && btn8 == LOW && btn9 == HIGH)  { 
    playMelody(notes7, rhythms7, sizeof(notes7)/sizeof(notes7[0]));
  }
  //BUTTON 1&2&3
  else if (btn1 == HIGH  && btn2 == HIGH && btn3 == HIGH && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    playMelody2(arp1, beat1, sizeof(arp1)/sizeof(arp1[0]));
  }
  //BUTTON 2&3&4
  else if (btn1 == LOW && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    playMelody2(arp2, beat2, sizeof(arp2)/sizeof(arp2[0]));
  }
  //BUTTON 3&4&5
  else if (btn1 == LOW && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    playMelody2(arp3, beat3, sizeof(arp3)/sizeof(arp3[0]));
  }
  //BUTTON 4&5&6
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    playMelody2(arp4, beat4, sizeof(arp4)/sizeof(arp4[0]));
  }
  //BUTTON 5&6&7
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH && btn7 == HIGH && btn8 == LOW && btn9 == LOW) {  
    playMelody2(arp5, beat5, sizeof(arp5)/sizeof(arp5[0]));
  }
  //BUTTON 6&7&8
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH && btn7 == HIGH && btn8 == HIGH && btn9 == LOW) {  
    playMelody2(arp6, beat6, sizeof(arp6)/sizeof(arp6[0]));
  }
  //BUTTON 7&8&9
  else if (btn1 == LOW && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == LOW && btn7 == HIGH && btn8 == HIGH && btn9 == HIGH) {  
    playMelody2(arp7, beat7, sizeof(arp7)/sizeof(arp7[0]));
  }
  
  //BUTTON 1&2&3&4
  else if (btn1 == HIGH  && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == LOW && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR, random(0,400));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 2&3&4&5
  else if (btn1 == LOW  && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR, random(400, 800));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 3&4&5&6
  else if (btn1 == LOW  && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR, random(800, 1200));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW);  
    delay(50);
  }
  //BUTTON 4&5&6&7
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH && btn7 == HIGH && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR, random(1200, 1600));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 5&6&7&8
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH && btn7 == HIGH && btn8 == HIGH && btn9 == LOW) {  
    tone(SPKR, random(1600, 2000));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 6&7&8&9
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == LOW && btn6 == HIGH && btn7 == HIGH && btn8 == HIGH && btn9 == HIGH) {  
    tone(SPKR, random(2000, 2400));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 1&2&3&4&5
  else if (btn1 == HIGH  && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == LOW && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR, random(0,2000));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 2&3&4&5&6
  else if (btn1 == LOW  && btn2 == HIGH && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH && btn7 == LOW && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR, random(200,2200));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 3&4&5&6&7
  else if (btn1 == LOW  && btn2 == LOW && btn3 == HIGH && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH && btn7 == HIGH && btn8 == LOW && btn9 == LOW) {  
    tone(SPKR, random(400,2400));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 4&5&6&7&8
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == HIGH && btn5 == HIGH && btn6 == HIGH && btn7 == HIGH && btn8 == HIGH && btn9 == LOW) {  
    tone(SPKR, random(800,2800));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  //BUTTON 5&6&7&8&9
  else if (btn1 == LOW  && btn2 == LOW && btn3 == LOW && btn4 == LOW && btn5 == HIGH && btn6 == HIGH && btn7 == HIGH && btn8 == HIGH && btn9 == HIGH) {  
    tone(SPKR, random(1200, 3200));    
    digitalWrite(led1, HIGH); 

     digitalWrite(led1, LOW); 
    delay(50);
  }
  else {                      // no button is pressed
    noTone(SPKR);             //turn OFF speaker sound
    digitalWrite(led1, LOW);  //turn OFF LED 1
  }


}

void playMelody(unsigned int notes[], unsigned int rhythms[], int length) {
  for (int i = 0; i < length; i++) {
    MIDI = makeMIDI(notes[i]);
    unsigned int rhythm = rhythms[i];
    tone(SPKR, MIDI);
    digitalWrite(led1, HIGH);
    delay(rhythm);

    noTone(SPKR);
    digitalWrite(led1, LOW);
    delay(50);
  }
}
void playMelody2(unsigned int notes[], unsigned int rhythms[], int length) {
  for (int i = 0; i < length; i++) {
    MIDI = makeMIDI(notes[i]);
    unsigned int rhythm = rhythms[i];
    tone(SPKR, MIDI);
    digitalWrite(led1, HIGH);
    delay(rhythm);

    noTone(SPKR);
    digitalWrite(led1, LOW);
    delay(100);
  }
}






