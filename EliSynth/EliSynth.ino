#define C4 60

#define DEFAULT_CADENCE_CAPACITY 4

class NoteDuration
{
  float start;    // relative to start of cadence or patter in beats, must be >= 0
  float duration; // relative to start of note in beats, must be >= 0
  
  public:
  NoteDuration(float s, float d)
  {
    if (s < 0)
    {
      Serial.print ("note start < 0: reassigned to 0");
      s = 0;
    }
    
    start = s;
    
    if (d < 0)
    {
      Serial.print ("note duration < 0: reassigned to 0");
      d = 0;
    }
    duration = d;
  }
  
  NoteDuration()
  {
    start = 0;
    duration = 0;
  }
};

class Cadence
{
  NoteDuration *durations;
  
  public: 
  int length;
  int capacity;
  
  Cadence ()
  {
    length = 0;
    durations = new NoteDuration[DEFAULT_CADENCE_CAPACITY];
  }
  
  Cadence (NoteDuration d[], int l)
  {
    durations = d;
    length = l;
    capacity = l;
  }
 
  void add(NoteDuration nd)
  {
    if (length == capacity)
    {
      NoteDuration *oldND = durations;
      NoteDuration *newND = new NoteDuration[capacity * 2];
      int i;
      
      for (i = 0; i < length; i++)
      {
        newND[i] = durations[i];
      }
      
      durations = newND;
      durations[i + 1] = nd;
      length++;
      capacity *= 2;
      
      free (oldND);
    }
  }
};

void Midi_Send(byte cmd, byte data1, byte data2) 
{
  Serial.write(cmd);
  Serial.write(data1);
  Serial.write(data2);
}

void setup()
{
}

void loop()
{
}


