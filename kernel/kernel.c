#define DGRAY_TXT 0x07
#define CYAN_TXT 0x0b
#define WHITE_TXT 0x0f

#define VERSION "0.0.1"

void clear_screen();
unsigned int prnt(char *color, char *message, unsigned int line);

void kernel_main() {
	clear_screen();
	prnt("7", "Welcome to", 0);
	prnt("b", "Aqua Kernel!", 1);
	prnt("f", "This is a test of version: 0.0.1", 3);
};

void clear_screen() {
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2)) {
		vidmem[i]=' ';
		i++;
		vidmem[i]=WHITE_TXT;
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
			if (*color=='b') {
				vidmem[i]=CYAN_TXT;
			} else if (*color=='7') {
				vidmem[i]=DGRAY_TXT;
			} else if (*color=='f') {
				vidmem[i]=WHITE_TXT;
			}
			i++;
		};
	};
	return(1);
}