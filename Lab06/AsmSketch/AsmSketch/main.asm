; Main program
 main:
 rcall asm_setup
 main_loop:
 rcall asm_loop
 rjmp main_loop
 asm_setup:
 ; Init the serial interface
 clr r0
 sts   UCSR0A, r0
 ldi   r24, 1<<RXEN0 | 1 << TXEN0 ; enable Rx & Tx
 sts   UCSR0B, r24
 ldi   r24, 1 << UCSZ00 | 1 << UCSZ01 ; asynchronous, no parity, 1 stop, 8 bits
 sts   UBRR0H, r0
 ldi   r24, 103
 sts   UBRR0L, r24
 ret
 asm_loop:
 ; print and wait
 rcall Print_Hello
 rcall wait

 ret
Print_Hello:    ; loading address and size of array
 ldi ZL, LOW(2*array)         ; r30
 ldi ZH, HIGH(2*array)        ; r31
 lpm r16, Z+                  ; Load the character pointed by Z registers (r30/r31)
 Loop:
 lds   r17, UCSR0A
 sbrs  r17, UDRE0   ; test the data buffer if data can be transmitted
 rjmp  Loop
 sts   UDR0, r16     ; send data contained in r16
 lpm r16, Z+        
 ; point to the next character
 tst r16
 ; check for string end - 0
 brne Loop
 ret
 ; simple function to wait for aprox 1 second by idle counting
 wait:
 ldi  R17, 0x53  
 LOOP0:  
 ldi  R18, 0xFB  
 LOOP1:  
 ldi  R19, 0xFF  
 LOOP2:  
 dec  R19   
 brne LOOP2
 dec  R18   
 brne LOOP1   
 dec  R17   
 brne LOOP0   
 ret
 ; string to be written, stored in the program memory
 array:
 .db "Assembly is fun",13,10,0