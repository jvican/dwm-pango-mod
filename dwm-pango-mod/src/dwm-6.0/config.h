/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[] = "Terminus Bold 18";

#define NUMCOLORS 9 
static const char colors[NUMCOLORS][ColLast][20] = {
// border foreground background
{ "#0F1D39", "#7A7A7A", "#1A1A1A" }, // 0 = normal
{ "#53A6A6", "#E0E0E0", "#1A1A1A" }, // 1 = selected
{ "#1A1A1A", "#CF4F88", "#1A1A1A" }, // 2 = red
{ "#1A1A1A", "#53A6A6", "#1A1A1A" }, // 3 = green
{ "#1A1A1A", "#914E89", "#1A1A1A" }, // 4 = yellow
{ "#1A1A1A", "#4779B3", "#1A1A1A" }, // 5 = blue
{ "#1A1A1A", "#47959E", "#1A1A1A" }, // 6 = cyan
{ "#1A1A1A", "#7E62B3", "#1A1A1A" }, // 7 = magenta
{ "#1A1A1A", "#899CA1", "#1A1A1A" }, // 8 = grey
};
static const unsigned int borderpx  = 2;        	/* border pixel of windows */
static const unsigned int snap      = 2;       	/* snap pixel */
static const Bool showbar           = True;     	/* False means no bar */
static const Bool topbar            = True;     	/* False means bottom bar */
static const unsigned int gappx		= 20;
static const unsigned int systrayspacing 	= 2; 	/* systray spacing */ 
static const Bool showsystray       		= False; /* False means no systray */ 

/* layout(s) */
static const float mfact      = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* first entry is default */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",    True, 		tile },    /* first entry is default */
	{ "><>",    False,		NULL },    /* no layout function means floating behavior */
	{ "[M]",    False,	    monocle },
	{ "[B]",	True,		bstack },
	{ "[C]",	True,		chat },
};

/* tagging */
static const Tag tags[] = {
    /* name    	layout       	mfact  	nmaster*/
    { "Main",  	&layouts[0], 	-1,    	-1 },
    { "Web",	&layouts[0], 	-1,  	-1 },
    { "Term",  	&layouts[0], 	-1,    	-1 },
    { "Code", 	&layouts[0], 	-1,    	-1 },
    { "Mult",  	&layouts[0], 	-1,    	-1 },
    { "Doc",  	&layouts[0], 	-1,    	-1 },
};

static const Rule rules[] = {
	/* class            instance    title       tags mask     isfloating   monitor */
	{ "Gimp",           NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",        NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Chromium",       NULL,       NULL,       1 << 1,       False,       -1 },
	{ "google-chrome-stable",       NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Vimprobable2",   NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Eclipse",        NULL,       NULL,       1 << 3,       False,       -1 },
	{ "Vlc",            NULL,       NULL,       1 << 4,       False,       -1 },
	{ "jetbrains-idea-ce", NULL,       NULL,       1 << 3,       False,       -1 },
	{ "Gedit",          NULL,       NULL,       1 << 3,       False,       -1 },
	{ "sublime_text",   NULL,       NULL,       1 << 3,       False,       -1 },
	{ "tabbed",         NULL,       NULL,       1 << 1,       False,       -1 },
	{ "MPlayer",        NULL,       NULL,       1 << 4,       False,       -1 },
	{ "Zathura",          NULL,       NULL,       1 << 5,       False,       -1 },
};


/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char  *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *amixerup[] = {"amixer", "-c", "0", "set", "Master", "3+", "unmute", NULL};
static const char *amixerdown[] = {"amixer", "-c", "0", "set", "Master", "3-", "unmute", NULL};
static const char *amixermut[] = {"amixer", "sset", "Master", "Toggle", NULL};
static const char *vimprobable[] = {"/home/hitchcock/Scripts/vimprobable2.sh", NULL};
static const char *poweroff[] = {"shutdown", "-h", "now"};
static const char *argos[] = {"/usr/bin/sudo", "/home/hitchcock/Scripts/wifi.sh", "argos", NULL};
static const char *prometheus[] = {"/usr/bin/sudo", "/home/hitchcock/Scripts/wifi.sh", "prometheus", NULL};
static const char *eduroam[] = {"/usr/bin/sudo", "/home/hitchcock/Scripts/wifi.sh", "eduroam", NULL};
static const char *intellij[] = {"/home/hitchcock/Scripts/intellij-exec.sh", NULL};
//static const char *brightup[]		=	{ "/home/hitchcock/Scripts/system", "brightness", "up", NULL };
//static const char *brightdown[]		=	{ "/home/hitchcock/Scripts/system", "brightness", "down", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ ControlMask,                 	XK_Down,  	moveresize,     {.v = (int []){ 0, 25, 0, 0 }}},
	{ ControlMask,                 	XK_Up,    	moveresize,     {.v = (int []){ 0, -25, 0, 0 }}},
	{ ControlMask,                 	XK_Right, 	moveresize,     {.v = (int []){ 25, 0, 0, 0 }}},
	{ ControlMask,                 	XK_Left,  	moveresize,     {.v = (int []){ -25, 0, 0, 0 }}},
	{ ControlMask|ShiftMask,       	XK_Down,  	moveresize,     {.v = (int []){ 0, 0, 0, 25 }}},
	{ ControlMask|ShiftMask,       	XK_Up,    	moveresize,     {.v = (int []){ 0, 0, 0, -25 }}},
	{ ControlMask|ShiftMask,       	XK_Right, 	moveresize,     {.v = (int []){ 0, 0, 25, 0 }}},
	{ ControlMask|ShiftMask,       	XK_Left,  	moveresize,     {.v = (int []){ 0, 0, -25, 0 }}},
	{ MODKEY,                 		XK_Left,   	cycleprev,  	{0} },
	{ MODKEY,                 		XK_Right,  	cyclenext,  	{0} },
	{ MODKEY|ShiftMask,				XK_Left,	cyclemoveprev,	{0} },
	{ MODKEY|ShiftMask,				XK_Right,	cyclemovenext,	{0} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = 1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = 1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = 0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,			            XK_s,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,           			XK_c,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = 1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Pause,  spawn,          {.v = poweroff } },
	{ MODKEY,                       XK_v,      spawn,          {.v = vimprobable } },
	{ MODKEY,                       XK_Up,     spawn,          {.v = amixerup } },
	{ MODKEY,                       XK_Down,   spawn,          {.v = amixerdown } },
	{ MODKEY,                       XK_Insert, spawn,          {.v = amixermut } },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = eduroam } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = prometheus } },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          {.v = argos } },
	{ MODKEY|ShiftMask,             XK_i,      spawn,          {.v = intellij } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
  	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  	{ MODKEY|ShiftMask,             XK_r,      reload,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

