unsigned long last_time = 0;
String comdata = "";
int port = 13;
char isn;

void setup()
{
    Serial.begin(115200);
    while(Serial.read()>=0){} //清空串口缓存  
    pinMode(port, OUTPUT);
}

void loop()
{
     while(Serial.available()>0)
     {           
          //comdata += char( Serial.read());
           isn = char( Serial.read());
           if(isn=='\n' &&comdata=="666")
           {
             Serial.println(comdata);    
             digitalWrite(port, HIGH);
             delay(10);
             digitalWrite(port, LOW);      
             comdata="";
           //  break;
           }

           else if(isn=='6')
           {
            comdata += isn;
            delay(2);      
           }         

           else if(comdata.length()>=4 && comdata!="666")
           {
            comdata="";
            } 
                 
//           else
//           {
//             comdata="";
//           }    
     }

}
