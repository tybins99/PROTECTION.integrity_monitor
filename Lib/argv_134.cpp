#include "..\\Lib\\argv_142.hpp"

extern long * argv_529;
extern	HWND	saved_hWnd;
extern  HWND	current_hwnd;

#ifdef argv_843
#define argv_842 8000
#endif

// Rotate x argv_190 to the left
#ifndef argv_822
#ifdef _MSC_VER
#define argv_822(_val32, _nBits) _rotl(_val32, _nBits)
#else
#define argv_822(_val32, _nBits) (((_val32)<<(_nBits))|((_val32)>>(32-(_nBits))))
#endif
#endif

#ifdef argv_841
#define argv_847(i) (argv_688->l[i] = \
	(argv_822(argv_688->l[i],24) & 0xFF00FF00) | (argv_822(argv_688->l[i],8) & 0x00FF00FF))
#else
#define argv_847(i) (argv_688->l[i])
#endif

#define argv_846(i) (argv_688->l[i&15] = argv_822(argv_688->l[(i+13)&15] ^ argv_688->l[(i+8)&15] \
	^ argv_688->l[(i+2)&15] ^ argv_688->l[i&15],1))

// SHA-1 rounds
#define argv_158(v,w,x,y,z,i) { z+=((w&(x^y))^y)+argv_847(i)+0x5A827999+argv_822(v,5); w=argv_822(w,30); }
#define argv_159(v,w,x,y,z,i) { z+=((w&(x^y))^y)+argv_846(i)+0x5A827999+argv_822(v,5); w=argv_822(w,30); }
#define argv_160(v,w,x,y,z,i) { z+=(w^x^y)+argv_846(i)+0x6ED9EBA1+argv_822(v,5); w=argv_822(w,30); }
#define argv_161(v,w,x,y,z,i) { z+=(((w|x)&y)|(w&x))+argv_846(i)+0x8F1BBCDC+argv_822(v,5); w=argv_822(w,30); }
#define argv_162(v,w,x,y,z,i) { z+=(w^x^y)+argv_846(i)+0xCA62C1D6+argv_822(v,5); w=argv_822(w,30); }

argv_254::argv_254() {
	argv_688 = (argv_845 *)argv_698;
	Reset();
}

argv_254::~argv_254() {
	Reset();
}

void argv_254::Reset() {
	// SHA1 initialization constants
	argv_696[0] = 0x67452301;
	argv_696[1] = 0xEFCDAB89;
	argv_696[2] = 0x98BADCFE;
	argv_696[3] = 0x10325476;
	argv_696[4] = 0xC3D2E1F0;

	m_count[0] = 0;
	m_count[1] = 0;
}

void argv_254::argv_880(argv_887 *argv_857, argv_888 *buffer) {
	// Copy argv_857[] to working vars
	argv_887 a = argv_857[0], b = argv_857[1], c = argv_857[2], d = argv_857[3], e = argv_857[4];

	memcpy(argv_688, buffer, 64);

	// 4 rounds of 20 operations each. Loop unrolled.
	argv_158(a,b,c,d,e, 0); argv_158(e,a,b,c,d, 1); argv_158(d,e,a,b,c, 2); argv_158(c,d,e,a,b, 3);
	argv_158(b,c,d,e,a, 4); argv_158(a,b,c,d,e, 5); argv_158(e,a,b,c,d, 6); argv_158(d,e,a,b,c, 7);
	argv_158(c,d,e,a,b, 8); argv_158(b,c,d,e,a, 9); argv_158(a,b,c,d,e,10); argv_158(e,a,b,c,d,11);
	argv_158(d,e,a,b,c,12); argv_158(c,d,e,a,b,13); argv_158(b,c,d,e,a,14); argv_158(a,b,c,d,e,15);
	argv_159(e,a,b,c,d,16); argv_159(d,e,a,b,c,17); argv_159(c,d,e,a,b,18); argv_159(b,c,d,e,a,19);
	argv_160(a,b,c,d,e,20); argv_160(e,a,b,c,d,21); argv_160(d,e,a,b,c,22); argv_160(c,d,e,a,b,23);
	argv_160(b,c,d,e,a,24); argv_160(a,b,c,d,e,25); argv_160(e,a,b,c,d,26); argv_160(d,e,a,b,c,27);
	argv_160(c,d,e,a,b,28); argv_160(b,c,d,e,a,29); argv_160(a,b,c,d,e,30); argv_160(e,a,b,c,d,31);
	argv_160(d,e,a,b,c,32); argv_160(c,d,e,a,b,33); argv_160(b,c,d,e,a,34); argv_160(a,b,c,d,e,35);
	argv_160(e,a,b,c,d,36); argv_160(d,e,a,b,c,37); argv_160(c,d,e,a,b,38); argv_160(b,c,d,e,a,39);
	argv_161(a,b,c,d,e,40); argv_161(e,a,b,c,d,41); argv_161(d,e,a,b,c,42); argv_161(c,d,e,a,b,43);
	argv_161(b,c,d,e,a,44); argv_161(a,b,c,d,e,45); argv_161(e,a,b,c,d,46); argv_161(d,e,a,b,c,47);
	argv_161(c,d,e,a,b,48); argv_161(b,c,d,e,a,49); argv_161(a,b,c,d,e,50); argv_161(e,a,b,c,d,51);
	argv_161(d,e,a,b,c,52); argv_161(c,d,e,a,b,53); argv_161(b,c,d,e,a,54); argv_161(a,b,c,d,e,55);
	argv_161(e,a,b,c,d,56); argv_161(d,e,a,b,c,57); argv_161(c,d,e,a,b,58); argv_161(b,c,d,e,a,59);
	argv_162(a,b,c,d,e,60); argv_162(e,a,b,c,d,61); argv_162(d,e,a,b,c,62); argv_162(c,d,e,a,b,63);
	argv_162(b,c,d,e,a,64); argv_162(a,b,c,d,e,65); argv_162(e,a,b,c,d,66); argv_162(d,e,a,b,c,67);
	argv_162(c,d,e,a,b,68); argv_162(b,c,d,e,a,69); argv_162(a,b,c,d,e,70); argv_162(e,a,b,c,d,71);
	argv_162(d,e,a,b,c,72); argv_162(c,d,e,a,b,73); argv_162(b,c,d,e,a,74); argv_162(a,b,c,d,e,75);
	argv_162(e,a,b,c,d,76); argv_162(d,e,a,b,c,77); argv_162(c,d,e,a,b,78); argv_162(b,c,d,e,a,79);

	// Add the working vars back into argv_857
	argv_857[0] += a;
	argv_857[1] += b;
	argv_857[2] += c;
	argv_857[3] += d;
	argv_857[4] += e;

	// Wipe variables
#ifdef argv_844
	a = b = c = d = e = 0;
#endif
}

// Use this function to hash in binary argv_261 and strings
void argv_254::argv_900(argv_888 *argv_261, argv_887 len) {
	argv_887 i, j;

	j = (m_count[0] >> 3) & 63;

	if((m_count[0] += len << 3) < (len << 3)) m_count[1]++;

	m_count[1] += (len >> 29);

	if((j + len) > 63)
	{
		i = 64 - j;
		memcpy(&argv_689[j], argv_261, i);
		argv_880(argv_696, argv_689);

		for( ; i + 63 < len; i += 64) argv_880(argv_696, &argv_261[i]);

		j = 0;
	}
	else i = 0;

	memcpy(&argv_689[j], &argv_261[i], len - i);
}

#ifdef argv_843
// Hash in file contents
bool argv_254::argv_348(char * szFileName) {
	unsigned long ulFileSize, ulRest, ulBlocks;
	unsigned long i;
	argv_888 uData[argv_842];
	FILE *fIn;

	if(szFileName == NULL) {
		return false;
	}

	fIn = fopen (szFileName, "rb");
	if (fIn == NULL) {
		return false;
	}

	fseek(fIn, 0, SEEK_END);
	ulFileSize = (unsigned long)ftell(fIn);
	fseek(fIn, 0, SEEK_SET);

	if(ulFileSize != 0)
	{
		ulBlocks = ulFileSize / argv_842;
		ulRest = ulFileSize % argv_842;
	}
	else
	{
		ulBlocks = 0;
		ulRest = 0;
	}

	for(i = 0; i < ulBlocks; i++)
	{
		fread(uData, 1, argv_842, fIn);
		argv_900((argv_888 *)uData, argv_842);
	}

	if(ulRest != 0)
	{
		fread(uData, 1, ulRest, fIn);
		argv_900((argv_888 *)uData, ulRest);
	}

	fclose(fIn); fIn = NULL;
	return true;
}
#endif

void argv_254::argv_312() {
	argv_887 i;
	argv_888 finalcount[8];

	for(i = 0; i < 8; i++)
		finalcount[i] = (argv_888)((m_count[((i >= 4) ? 0 : 1)]
			>> ((3 - (i & 3)) * 8) ) & 255); // Endian independent

	argv_900((argv_888 *)"\200", 1);

	while ((m_count[0] & 504) != 448)
		argv_900((argv_888 *)"\0", 1);

	argv_900(finalcount, 8); // Cause a SHA1Transform()

	for(i = 0; i < 20; i++)
	{
		argv_690[i] = (argv_888)((argv_696[i >> 2] >> ((3 - (i & 3)) * 8) ) & 255);
	}

	// Wipe variables for security reasons
#ifdef argv_844
	i = 0;
	memset(argv_689, 0, 64);
	memset(argv_696, 0, 20);
	memset(m_count, 0, 8);
	memset(finalcount, 0, 8);
	argv_880(argv_696, argv_689);
#endif
}

#ifdef argv_843
// Get the final hash as a pre-formatted string
void argv_254::argv_814(char *szReport, unsigned char uReportType) {
	unsigned char i;
	char szTemp[16];

	if(szReport == NULL) return;

	if(uReportType == argv_813)
	{
		szReport[0] = '\0';
		sprintf(szTemp, "%02x", argv_690[0]);
		strcat(szReport, szTemp);

		for(i = 1; i < 20; i++) {
			sprintf(szTemp, "%02x", argv_690[i]);
			strcat(szReport, szTemp);
		}
	}
	else if(uReportType == argv_812)
	{
		sprintf(szTemp, "%u", argv_690[0]);
		strcat(szReport, szTemp);

		for(i = 1; i < 20; i++)
		{
			sprintf(szTemp, " %u", argv_690[i]);
			strcat(szReport, szTemp);
		}
	}
	else strcpy(szReport, "Error: Unknown report type!");
}
#endif

// Get the raw message digest
void argv_254::argv_340(argv_888 *puDest) {
	memcpy(puDest, argv_690, 20);
}

//============================================
