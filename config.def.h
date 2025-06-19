/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] = "#11111b",     /* after initialization */
	[INPUT] = "#1e1e2e",    /* during input */
	[FAILED] = "#45475a",   /* wrong password */
	[CAPS] = "#f9e2af	",    /* CapsLock on */
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",       STRING,  &colorname[INIT] },
		{ "color4",       STRING,  &colorname[INPUT] },
		{ "#45475a",      STRING,  &colorname[FAILED] },
		{ "color1",       STRING,  &colorname[CAPS] },
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* default message */
static const char * message = "Suckless: Software that sucks less.";

/* text color */
static const char * text_color = "#f5e0dc";

/* text size (must be a valid size) */
static const char * font_name = "10x20";
