/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"
#include <stdio.h>

// Definitions
#define MESSAGE_LENGTH (255u)
#define TRUE (1u)
#define FALSE (0u)

#define CLEAR_TERMINAL "\x1b[2J"
#define CURSOR_HOME_TERMINAL "\x1b[H"

// Externals
extern void user_core_initalize(void);
extern void uart_open(void);
extern void uart_close(void);
extern void uart_read(void);
extern void uart_write(char *data, int clear);

/* [] END OF FILE */
