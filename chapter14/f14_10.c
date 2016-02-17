struct gas {
	float distance;
	float gals;
	float mpg;
};

struct gas make_mpg (struct gas temp)
{
	if (temp.gals > 0)
		temp.mpg = temp.distance / temp.gals;
	else
		temp.mpg = -1.0;
	return temp;
}

void make_mpg2 (struct gas *pg)
{
	if (pg->gals > 0)
		pg->mpg = pg->distance / pg->gals;
	else
		pg->mpg = -1.0;
}