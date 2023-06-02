.include "/sdcard/Download/codes/as3/equation1/m328Pdef.inc"

	ldi r17,0b11110011
	out DDRD,r17
	ldi r17,0b11111111
	out PORTD,r17
	ldi r18,0b00000011
	out DDRB,r18

mainloop:  
	in r17,PIND
	
	mov r18,r17
	ldi r19,0b00000100
	and r18,r19
	lsr r18
	lsr r18

	mov r20,r17
	ldi r19,0b00001000
	and r20,r19
	lsr r20
	lsr r20
	lsr r20

	ldi r22,0b00000000
	ldi r23,0b00000000

	mov r22,r18
	eor r22,r20
	mov r23,r18
	or r23,r20
	lsl r23


	or r23,r22
	out PORTB,r23

	rjmp mainloop

Start:
	rjmp Start
	
