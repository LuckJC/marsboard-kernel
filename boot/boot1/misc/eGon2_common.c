/*
**********************************************************************************************************************
*											        eGon
*						           the Embedded GO-ON Bootloader System
*									       eGON libc sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    : eGon2_common.c
*
* By      : Jerry
*
* Version : V2.00
*
* Date	  :
*
* Descript:
**********************************************************************************************************************
*/
#include <stdarg.h>
#include "format_transformed.h"
#include "egon2.h"


/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
static __u32 mem_puts(const char *str, char *p )
{
    __u32 len = 0;

	while( *str != '\0' )
	{
		if( *str == '\n' )                      // if current character is '\n', insert and output '\r'
		{
		    *p++ = '\r';
		    len ++;
        }
        *p++ = *str++;
        len ++;
	}

	return len;
}

/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void wlibc_uprintf( const char * str, ...)
{
	char string[16], str_store[256];
	char *p, *q = str_store;
	__s32 hex_flag ;
	va_list argp;

	va_start( argp, str );

	while( *str )
	{
		if( *str == '%' )
		{
			++str;
			p = string;
			hex_flag = HEX_X;
			switch( *str )
			{
				case 'd': int_to_string_dec( va_arg( argp,  __s32 ), string );
                          q += mem_puts( p, q );
						  ++str;
						  break;
				case 'x': hex_flag = HEX_x;	         // jump to " case 'X' "
				case 'p':
				case 'X': int_to_string_hex( va_arg( argp,  __s32 ), string, hex_flag );
						  q += mem_puts( p, q );
                          ++str;
						  break;
				case 'u': Uint_to_string_dec( va_arg( argp,  __s32 ), string );
						  q += mem_puts( p, q );
						  ++str;
						  break;
				case 'c': *q++ = va_arg( argp,  __s32 );
						  ++str;
						  break;
				case 's': q += mem_puts( va_arg( argp, char * ), q );
						  ++str;
						  break;
				case 'l':
					{
						__u32 high;
						__u32 low;

						if( str[1] == 'l' && ( str[2] == 'x' || str[2] == 'X' ) )
						{
							low = va_arg( argp, __u32 );
							high = va_arg( argp, __u32 );
							if( str[2] == 'x' )
								hex_flag = 'x';
							else
								hex_flag = 'X';
							int_to_string_hex( high, string, hex_flag );
							q += mem_puts( p, q );
							int_to_string_hex( low, string, hex_flag );
							q += mem_puts( p+2, q );
							str += 3;
						  	break;
						}
						else
						{
							int_to_string_dec( va_arg( argp,  __s32 ), string );
                          	q += mem_puts( p, q );
						  	++str;
						  	break;
						}
					}
				default : *q++ = '%';                                    // if current character is not Conversion Specifiers 'dxpXucs',
						  *q++ = *str++;                                 // output directly '%' and current character, and then
						                                                 // let 'str' point to next character.
			}
		}
		else
		{
			if( *str == '\n' )                      // if current character is '\n', insert and output '\r'
				*q++ = '\r';

            *q++ = *str++;
		}
	}

	va_end( argp );

    *q = 0;

	wBoot_uprintf((void *)str_store);

	return ;
}
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void wlibc_ntprintf( const char * str, ...)
{
	char string[16], str_store[256];
	char *p, *q = str_store;
	__s32 hex_flag ;
	va_list argp;

	va_start( argp, str );

	while( *str )
	{
		if( *str == '%' )
		{
			++str;
			p = string;
			hex_flag = HEX_X;
			switch( *str )
			{
				case 'd': int_to_string_dec( va_arg( argp,  __s32 ), string );
                          q += mem_puts( p, q );
						  ++str;
						  break;
				case 'x': hex_flag = HEX_x;	         // jump to " case 'X' "
				case 'p':
				case 'X': int_to_string_hex( va_arg( argp,  __s32 ), string, hex_flag );
						  q += mem_puts( p, q );
                          ++str;
						  break;
				case 'u': Uint_to_string_dec( va_arg( argp,  __s32 ), string );
						  q += mem_puts( p, q );
						  ++str;
						  break;
				case 'c': *q++ = va_arg( argp,  __s32 );
						  ++str;
						  break;
				case 's': q += mem_puts( va_arg( argp, char * ), q );
						  ++str;
						  break;
				case 'l':
					{
						__u32 high;
						__u32 low;

						if( str[1] == 'l' && ( str[2] == 'x' || str[2] == 'X' ) )
						{
							low = va_arg( argp, __u32 );
							high = va_arg( argp, __u32 );
							if( str[2] == 'x' )
								hex_flag = 'x';
							else
								hex_flag = 'X';
							int_to_string_hex( high, string, hex_flag );
							q += mem_puts( p, q );
							int_to_string_hex( low, string, hex_flag );
							q += mem_puts( p+2, q );
							str += 3;
						  	break;
						}
						else
						{
							int_to_string_dec( va_arg( argp,  __s32 ), string );
                          	q += mem_puts( p, q );
						  	++str;
						  	break;
						}
					}
				default : *q++ = '%';                                    // if current character is not Conversion Specifiers 'dxpXucs',
						  *q++ = *str++;                                 // output directly '%' and current character, and then
						                                                 // let 'str' point to next character.
			}
		}
		else
		{
			if( *str == '\n' )                      // if current character is '\n', insert and output '\r'
				*q++ = '\r';

            *q++ = *str++;
		}
	}

	va_end( argp );

    *q = 0;

	wBoot_ntprintf((void *)str_store);

	return ;
}
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void wlibc_sprintf( char *str_store, const char * str, ...)
{
	char string[16];
	char *p, *q = str_store;
	__s32 hex_flag;
	va_list argp;

	va_start( argp, str );

	while( *str )
	{
		if( *str == '%' )
		{
			++str;
			p = string;
			hex_flag = HEX_X;
			switch( *str )
			{
				case 'd': int_to_string_dec( va_arg( argp,  __s32 ), string );
                          q += mem_puts( p, q );
						  ++str;
						  break;
				case 'x': hex_flag = HEX_x;	         // jump to " case 'X' "
				case 'p':
				case 'X': int_to_string_hex( va_arg( argp,  __s32 ), string, hex_flag );
						  q += mem_puts( p, q );
                          ++str;
						  break;
				case 'u': Uint_to_string_dec( va_arg( argp,  __s32 ), string );
						  q += mem_puts( p, q );
						  ++str;
						  break;
				case 'c': *q++ = va_arg( argp,  __s32 );
						  ++str;
						  break;
				case 's': q += mem_puts( va_arg( argp, char * ), q );
						  ++str;
						  break;
				case 'l':
					{
						__u32 high;
						__u32 low;

						if( str[1] == 'l' && ( str[2] == 'x' || str[2] == 'X' ) )
						{
							low = va_arg( argp, __u32 );
							high = va_arg( argp, __u32 );
							if( str[2] == 'x' )
								hex_flag = 'x';
							else
								hex_flag = 'X';
							int_to_string_hex( high, string, hex_flag );
							q += mem_puts( p, q );
							int_to_string_hex( low, string, hex_flag );
							q += mem_puts( p+2, q );
							str += 3;
						  	break;
						}
						else
						{
							int_to_string_dec( va_arg( argp,  __s32 ), string );
                          	q += mem_puts( p, q );
						  	++str;
						  	break;
						}
					}
				default : *q++ = '%';                                    // if current character is not Conversion Specifiers 'dxpXucs',
						  *q++ = *str++;                                 // output directly '%' and current character, and then
						                                                 // let 'str' point to next character.
			}
		}
		else
		{
			if( *str == '\n' )                      // if current character is '\n', insert and output '\r'
				*q++ = '\r';

            *q++ = *str++;
		}
	}

	va_end( argp );

    *q = 0;

	return ;
}


