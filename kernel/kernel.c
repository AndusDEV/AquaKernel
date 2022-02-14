#define BLACK_CLR 0x00
#define BLUE_CLR 0x01
#define GREEN_CLR 0x02
#define CYAN_CLR 0x03
#define RED_CLR 0x04
#define MAGENTA_CLR 0x05
#define BROWN_CLR 0x06
#define LGRAY_CLR 0x07
#define DGRAY_CLR 0x08
#define LBLUE_CLR 0x09
#define LGREEN_CLR 0x0a
#define LCYAN_CLR 0x0b
#define LRED_CLR 0x0c
#define LMAGENTA_CLR 0x0d
#define YELLOW_CLR 0x0e
#define WHITE_CLR 0x0f

#define VERSION "0.0.1"

void clear_screen();
unsigned int prnt(char *color, char *message, unsigned int line);

/* Main Kernel */
void kernel_main() {
	clear_screen();
	prnt("3", "  ____     \n / __ \\__/\\ \n \\/ \\____/ ", 0);
	prnt("7", "Welcome to", 3);
	prnt("b", "Aqua Kernel!", 4);
	prnt("f", "This is a test of version: 0.0.1", 6);
	prnt("a", "Type \'h\' to see all commands", 7);
	prnt("4", "Keyboard don\'t work now..", 8);
};

void clear_screen() {
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2)) {
		vidmem[i]=' ';
		i++;
		vidmem[i]=WHITE_CLR;
		i++;
	};
};

// Method for color will be better. e.x. prnt("&7Welcome to\n&bAqua Kernel!", 0);
//                                        &7 = Gray   \n = New Line   &b = Cyan
unsigned int prnt(char *color, char *message, unsigned int line) {
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;

	i=(line*80*2);

	while(*message != 0) {
		if(*message == '\n') {
			line++;
			i=(line*80*2);
			*message++;
		} else {
			vidmem[i] = *message;
			*message++;
			i++;
			if (*color=='0') {
				vidmem[i]=BLACK_CLR;
			} else if (*color=='1') {
				vidmem[i]=BLUE_CLR;
			} else if (*color=='2') {
				vidmem[i]=GREEN_CLR;
			} else if (*color=='3') {
				vidmem[i]=CYAN_CLR;
			} else if (*color=='4') {
				vidmem[i]=RED_CLR;
			} else if (*color=='5') {
				vidmem[i]=MAGENTA_CLR;
			} else if (*color=='6') {
				vidmem[i]=BROWN_CLR;
			} else if (*color=='7') {
				vidmem[i]=LGRAY_CLR;
			} else if (*color=='8') {
				vidmem[i]=DGRAY_CLR;
			} else if (*color=='9') {
				vidmem[i]=LBLUE_CLR;
			} else if (*color=='a') {
				vidmem[i]=LGREEN_CLR;
			} else if (*color=='b') {
				vidmem[i]=LCYAN_CLR;
			} else if (*color=='c') {
				vidmem[i]=LRED_CLR;
			} else if (*color=='d') {
				vidmem[i]=LMAGENTA_CLR;
			} else if (*color=='e') {
				vidmem[i]=YELLOW_CLR;
			} else if (*color=='f') {
				vidmem[i]=WHITE_CLR;
			}
			i++;
		};
	};
	return(1);
}