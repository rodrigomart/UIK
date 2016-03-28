#ifndef UIK_POINT
#define UIK_POINT


namespace UIK {
	/**
	 * @class Point
	 * @ingroup UIK
	 *
	 * UIK::Point is used for the coordinates on the screen.
	 */
	class Point {
		public:
			/** Coordinate X */
			float X;

			/** Coordinate Y */
			float Y;


			/** Point */
			Point();

			/**
			 * Point
			 *
			 * @param x Coordinade x.
			 * @param y Coordinade y.
			 */
			Point(float x, float y);
	};
}

#endif
