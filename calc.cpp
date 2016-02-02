#define 	BASIC_INCR_RATE			0.3


class calc_incr
{
	int base_sal;

	public:

	int calc_basic_incr(int in);
	int calc_rating_incr(int in);
	int calc_demand_incr(int in);

};

calc_incr::calc_incr()
{
	base_sal = 0;
}

int calc_incr::calc_basic_incr(int in)
{
	return (in * BASIC_INCR_RATE);
}

int calc_incr::calc_rating_incr(int in)
{
	return ( (in * RATING_INCR_RATE) * (RATING * 10) * (RATING) );
}
