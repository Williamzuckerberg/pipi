#define RC_ERROR 1
#define RC_SUCCESS 0
#define SERVPORT 80
#define SERVIP "58.254.39.6"
#define RECV_TEMP_FILE "temp.resrc"
#define RESOURCE_FILE "pipi.resrc"
#define RECV_CONSTANT_LENGTH 8
#define ADDR_IN_LENGTH 128
#define ADDR_MAX_LENGTH 192//(128 *3)/2
#define ADDR_BASE64_HEAD "thunder://"
#define ADDR_BASE64_HEAD_LENGTH 10
#define RECV_BUFFER_SIZE 4096
#define FIRST_PACKET_HEAD_SIZE 12// 3*4B = 12
#define RECV_FIRST_PACKET_FLAG 1
#define AES_KEY_LENGTH 16
#define AES_DECODE_LENGTH 16
#define USEFUL_LINK_HTTP "http://"
#define USEFUL_LINK_HTTP_LENGTH 7
#define USEFUL_LINK_FTP "ftp://"
#define USEFUL_LINK_FTP_LENGTH 6
#define COMPOSE_MAX_BUFFER_SIZE 336//336 = 126+8+4+9+4+128+55+2

class PP_Downloader
{
    public:
        PP_Downloader();
        ~PP_Downloader();
        int parse_address();
        int parse_listfile();
        int decode_listfile();
        int download_file();
    private:
        int compose_requestpacket(unsigned char *buffer, int *length);
        void int2ascii(char *buf, int len_in, int *len_out);
        void print_mem16(unsigned char *mem);
        
        int set_addr(unsigned char *addr_input);
        unsigned char *get_addr();
        int set_recv_constant();
        unsigned char *get_recv_constant();
        int set_aeskey(unsigned char * key);
        unsigned char *get_aeskey();	
        
        unsigned char recv_constant[RECV_CONSTANT_LENGTH];
        unsigned char addr[ADDR_IN_LENGTH];
        unsigned char aes_key[AES_KEY_LENGTH];
};
