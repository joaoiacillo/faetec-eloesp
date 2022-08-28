#INCLUDE <P16F628A.INC>
	__CONFIG  _BODEN_ON & _CP_OFF & _PWRTE_ON & _WDT_OFF & _LVP_OFF & _MCLRE_ON & _XT_OSC

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Banks					;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
#DEFINE	BANK0	BCF STATUS, RP0
#DEFINE	BANK1	BSF STATUS, RP0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Inputs					;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	
#DEFINE RUNBTN PORTA, 1  ; Starts the effect once pressed
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Constants					;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
#DEFINE INITIAL B'00000001'  ; The initial led formation once run btn is pressed
#DEFINE	MAX	0x03  ; The number of times the effect will repeat both ways. 
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Variables					;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
DCounter1 EQU 0X0C
DCounter2 EQU 0X0D
DCounter3 EQU 0X0E
 
CBLOCK	0x20
	REPEAT
ENDC


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Reset Vector				;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
	ORG	0x00
	GOTO	START

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Delay					;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
DELAY
	MOVLW	0X5c
	MOVWF	DCounter1
	MOVLW	0X26
	MOVWF	DCounter2
	MOVLW	0X0b
	MOVWF	DCounter3
LOOP
	DECFSZ	DCounter1, 1
	GOTO	LOOP
	DECFSZ	DCounter2, 1
	GOTO	LOOP
	DECFSZ	DCounter3, 1
	GOTO	LOOP
	NOP
	RETURN

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Program					;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
START
	BANK1
	CLRF	TRISB
	MOVLW	B'00000010'  ; Bit 1 -> Input
	MOVWF	TRISA
	BANK0
	
MAIN	
	; The mcu is useless until the run button is
	; pressed. That's when the magic happens!
	BTFSC	RUNBTN
	GOTO	MAIN
	
	; Moving the initial formation to PORTB.
	MOVLW	INITIAL
	MOVWF	PORTB
	
	; Setting REPEAT value to MAX.
	MOVLW	MAX
	MOVWF	REPEAT
	
SHIFTL  ; Shifiting 1 bit to the left.
	; This is the same as adding PORTB to PORTB.
	CALL	DELAY
	RLF	PORTB
	
	; Decrements REPEAT, and if it's 0, then will stop
	; shifting to the left
	DECFSZ	REPEAT
	GOTO	SHIFTL
	
	; Setting REPEAT value to MAX.
	MOVLW	MAX
	MOVWF	REPEAT
	
SHIFTR	; Shifting 1 bit to the right.
	; This is the same as PORTB / 2
	CALL	DELAY
	RRF	PORTB
	
	; Decrements REPEAT, and if it's 0, then will stop
	; shifting to the right
	DECFSZ	REPEAT
	GOTO	SHIFTR
	
	; The moment everyone's been waiting for...
	; The end of the effect when everything is turned
	; off.
	CALL	DELAY
	CLRF	PORTB
	
	
	GOTO MAIN
	END
