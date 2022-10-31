# Muiltimeter
- Simple multimeter that can measure :
                  (current-Voltage-Resistance-Frequency
                  -Inductance-Capacitance) .
         - By using the virtual terminal we print the modes for  the                                   
                user ,  that he can  choose between them.
         - 0-->Ammeter
         - 1-->Voltameter
         - 2-->Ohmmeter
         - 3-->Freq-meter
         - 4-->Ind-meter
         - 5-->Cap-meter
         - If the user wants to change the type of the multimeter  
               Press q and then rechoose the mode .
• components :
       - ATMEGA32
       - 1N4001 "Diode"
       - ACS712 "Current Sensor"
       - Capacitors & resistances
       - IND-Air  "Inductor"
       - BATTERY(5v)
       - PUSH BUTTON   "For reset"
       - LM016L "LCD"
       - LM358N "OP-AMP"
       - virtual terminal
       - Multiplixer (simple one"2:1" using 2 AND & OR gates)
• Used Drivers :
       - DIO                  "MCAL"
       - ADC                 "MCAL'
       - ICU(Timer1)     "MCAL"
       - UART               ''MCAL"
       - LCD                  "HAL" 
• Notes :
       - If the user entered a number out of range (0:6) , We print 
               invalid choice and make him choose again .
       - If we want to emblements  it we should change the OP- 
               AMP  with CD40106B"Schmitt trigger "  to avoid edge   
               metastability as it has    Hysteresis  .
       - This simple model of multimeter ONLY can mesare in a 
               particular range "which we can enhance it by using a large  
               Multiplixer to handle it " .
             // Ohmeter         "At fixed 30k"
                 1k   ---> 32.5k        //
             // Voltameter  :  "At votage divider 1:6"
                   0 V ---> 30V         //                 
             // Ammeter     :  "At fixed 5v vcc"
                    0     ---> 5A         //
             // Ind-meter    :   "At fixed 2uF"
                     1uH ---> 31mH  //
             // Cap-meter   :   "At fixed 50uH"
                      1uF  ---> 11mF  //
