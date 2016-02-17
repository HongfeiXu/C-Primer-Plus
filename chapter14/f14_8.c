struct fullname {
	char fname[20];
	char lname[20];
};
struct bard {
	struct fullname name;
	int born;
	int died;
};
struct bard willie;
struct bard *pt = &willie;

// a
willie.born;
// b
pt->born;
// c
scanf ("%d", &willie.born);
// d
scanf ("%d", &pt->born);
// e
scanf ("%s", willie.name.lname);
// f
scanf ("%s", pt->name.lname);
// g
willie.name.fname[2];
// h
strlen (willie.name.fname) + strlen (willie.name.lname);