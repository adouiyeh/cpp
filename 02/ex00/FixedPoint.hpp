#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

class FixedPoint
{
    private:
        int _num_val;
        static const int _frac_bits = 8;
    public:
        FixedPoint();
        FixedPoint(const FixedPoint &fixed_point);
        ~FixedPoint();

}



FixedPoint::FixedPoint(): _num_val(0) {}



#endif