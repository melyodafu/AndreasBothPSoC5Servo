/* ========================================
 *
 * AUTHOR:      Andreas BOTH
 * DATE:        2024-04-14
 * COURSE ID:   tx00db04
 * Description: PSoC course excercise 2, 
 *              Position control of a servo motor using PWM and interrupts
 * ========================================
*/
#include "project.h"
#include <stdio.h>  //needed for sprintf()

#define MY_NAME "Andreas Both"
/* defines different target values for the servo, could be mapped to angles*/
#define SERVOPOSITION1 1000
#define SERVOPOSITION2 1200
#define SERVOPOSITION3 1400
#define SERVOPOSITION4 1600
#define SERVOPOSITION5 1800

/*define and declare enum type to change target Positions later on*/
enum servoPositions {position1,position2,position3,position4,position5};
volatile enum servoPositions gPositionCounter;

/*used to keep track of the current position and the difference to the target position*/
volatile int gCurrentPosition=1500;
volatile int gTargetPosition =1500;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    char transmitBuffer[50]; 
    /*Start ISR for UART communication 
    The RX interrupt is used to check for user input in the controll terminal
    since it's not important what the exact input is, it is sufficent to check for wether 
    there is an input at all
    */
    isr_rx_ClearPending();
    isr_rx_Start();
    
    /*Start ISR for the continuos change of the servoPosition*/
    isr_pwm_ClearPending();
    isr_pwm_Start();
    
    /*Start PWM module*/
    PWM1_Start();
    
    /*Start UART communication module to output the current value of gCurrentPosition*/
    UART_Start();
    UART_PutCRLF(0);
    UART_PutString(MY_NAME);
    UART_PutCRLF(0);
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        //Transmit current position
        sprintf(transmitBuffer,"current position: %i",gCurrentPosition);
        UART_PutString(transmitBuffer);
        UART_PutCRLF(0);
        //change value of gTargetPosition to specified pulse width
        CyGlobalIntDisable
        switch(gPositionCounter){
            case position1: gTargetPosition = SERVOPOSITION1;break;
            case position2: gTargetPosition = SERVOPOSITION2;break;
            case position3: gTargetPosition = SERVOPOSITION3;break;
            case position4: gTargetPosition = SERVOPOSITION4;break;
            case position5: gTargetPosition = SERVOPOSITION5;break;
            default: PWM1_WriteCompare(1500);break;
        }
        PWM1_WriteCompare(gCurrentPosition); //write pulse width to PWM module
        CyGlobalIntEnable
       
    }
}

/* [] END OF FILE */
