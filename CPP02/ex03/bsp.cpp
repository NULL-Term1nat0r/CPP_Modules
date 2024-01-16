/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:42:21 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/07 22:28:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
// bool bsp( Point const a, Point const b, Point const c, Point const point){

// }

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	// Calculate the barycentric coordinates
	float alpha = ((b.getPointY().toFloat() - c.getPointY().toFloat()) * (point.getPointX().toFloat() - c.getPointX().toFloat()) + (c.getPointX().toFloat() - b.getPointX().toFloat()) * (point.getPointY().toFloat() - c.getPointY().toFloat())) /
	((b.getPointY().toFloat() - c.getPointY().toFloat()) * (a.getPointY().toFloat() - c.getPointX().toFloat()) + (c.getPointX().toFloat() - b.getPointX().toFloat()) * (a.getPointY().toFloat() - c.getPointY().toFloat()));

	float beta = ((c.getPointY().toFloat() - a.getPointY().toFloat()) * (point.getPointX().toFloat() - c.getPointX().toFloat()) + (a.getPointX().toFloat() - c.getPointX().toFloat()) * (point.getPointY().toFloat() - c.getPointY().toFloat())) /
				((b.getPointY().toFloat() - c.getPointY().toFloat()) * (a.getPointX().toFloat() - c.getPointX().toFloat()) + (c.getPointX().toFloat() - b.getPointX().toFloat()) * (a.getPointY().toFloat() - c.getPointY().toFloat()));

	float gamma = 1 - alpha - beta;

	// Check if all barycentric coordinates are within [0, 1]
	return alpha > 0 && beta > 0 && gamma > 0 &&
           alpha < 1 && beta < 1 && gamma < 1;
}

// bool bsp(Point a, Point b, Point c, Point point) {
//     // Calculate the barycentric coordinates
//     float alpha = ((b.y.toFloat() - c.y.toFloat()) * (point.x.toFloat() - c.x.toFloat()) + (c.x.toFloat() - b.x.toFloat()) * (point.y.toFloat() - c.y.toFloat())) /
//                   ((b.y.toFloat() - c.y.toFloat()) * (a.x.toFloat() - c.x.toFloat()) + (c.x.toFloat() - b.x.toFloat()) * (a.y.toFloat() - c.y.toFloat()));

//     float beta = ((c.y.toFloat() - a.y.toFloat()) * (point.x.toFloat() - c.x.toFloat()) + (a.x.toFloat() - c.x.toFloat()) * (point.y.toFloat() - c.y.toFloat())) /
//                  ((b.y.toFloat() - c.y.toFloat()) * (a.x.toFloat() - c.x.toFloat()) + (c.x.toFloat() - b.x) * (a.y - c.y));

//     float gamma = 1 - alpha - beta;

//     // Check if all barycentric coordinates are within [0, 1] (including endpoints)
//     return alpha >= 0 && beta >= 0 && gamma >= 0 &&
//            alpha <= 1 && beta <= 1 && gamma <= 1;
// }
