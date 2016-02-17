/*
 *  定义一个含有12个第3题中那种类型的结构的数组，
 *  并把它初始化为一个年份（非闰年）
 *
 * */


struct month {
	char name[20];  // 月份名
	char abb[4];    // 3个字母月份名缩写
	int day;        // 该月的天数
	int id;         // 月份号
};

struct month year[12] = {
	{
		"January",
		"Jan",
		31,
		1
	},
	{
		"Febrary",
		"Feb",
		28,
		2
	},
	{
		"March",
		"Mar",
		31,
		3
	},
	{
		"April",
		"Apr",
		30,
		4
	},
	{
		"May",
		"May",
		31,
		5
	},
	{
		"June",
		"Jun",
		30,
		6
	},
	{
		"July",
		"Jul",
		31,
		7
	},
	{
		"Augst",
		"Aug",
		31,
		8
	},
	{
		"September",
		"Sep",
		30,
		9
	},
	{
		"October",
		"Oct",
		31,
		10
	},
	{
		"November",
		"Nov",
		30,
		11
	},
	{
		"December",
		"Dec",
		31,
		12
	}
};
