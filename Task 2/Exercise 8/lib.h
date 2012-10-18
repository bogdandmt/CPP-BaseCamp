/**
 * @file	func.h
 * @brief	Structs and prototypes of functions for task 2 exercise 8
 */

typedef unsigned int UI;

struct Point
{
	float x, y, z;
};

/**
 * @brief	The function sorts the sequence of points
 * @param	[in, out] seq The sequence of points
 * @param	[in] size The size of sequence
 * @return	void
 */
void Sort(Point *seq, const UI &size);

/**
 * @brief	The function calculates the distance between two points
 * @param	[in] p1 First point
 * @param	[in] p2 Second point
 * @return	double The distance between two points
 */
double Dist(const Point &p1, const Point &p2);