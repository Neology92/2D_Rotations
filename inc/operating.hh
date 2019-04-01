#pragma once

#include <string.h>
#include <fstream>

#include "gnuplot_link.hh"
#include "Rectangle.hh"

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