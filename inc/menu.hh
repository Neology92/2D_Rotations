#pragma once

#include <iostream>

#include "operating.hh"

/* 
 *  operating.hh - this file contains annoucements of:
 *  operating functions, which are needed to visual side of program, 
 *  but also writing, reading and accessory functions (i.e. debug-helpers)
 */


/**
 * @brief Shows main menu on standard output stream
 */
void show_options();

/**
 * @brief Calls Operates on rectangle according users choice
 *
 * @param rec - object, which has to bo edited
 */
void menu(Rectangle& rec);
