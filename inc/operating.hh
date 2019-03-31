#pragma once

#include <iostream>
#include <string.h>
#include <fstream>

#include "gnuplot_link.hh"
#include "Rectangle.hh"

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

/**
 * @brief Draws rectangle in gnuPlot
 * 
 */
int gnuPlotDraw(Rectangle rect);


/*!
 * Saving rectangle coordiantes to file, from which 
 * GnuPlot program will read, and draw
 * 
 * \param[in] filename - filename to write
 * 
 * \param[in] R - object of class Rectangle - to save
 * 
 * \retval true - success,
 * \retval false - failed.
 */
bool WriteToFileExample(std::string filename, Rectangle R);


/*!
 * Pushing rectangle data (coordinates) to stream
 * 
 * \param[in] output_stream - stream to which data will be pushed
 * 
 * \param[in] R - object of class Rectangle - to push

 * \retval true - success,
 * \retval false - failed.
 */
void WriteToStreamExample(std::ostream& output_stream, Rectangle R);