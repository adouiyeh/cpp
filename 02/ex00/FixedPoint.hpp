#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

class FixedPoint
{
    private:
        int _numVal;
        static const int _fracBits = 8;
    public:
        FixedPoint();
        FixedPoint(const FixedPoint &fixed_point);
        ~FixedPoint();

};

FixedPoint::FixedPoint(): _numVal(0) {}


#endif