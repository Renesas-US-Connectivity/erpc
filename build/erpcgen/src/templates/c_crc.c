/*
 * AUTOMATICALLY GENERATED FILE - DO NOT EDIT
 */

// Generated from /home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/templates/c_crc.template
extern const char * const kCCrc;

const char * const kCCrc = 
"{% if mlComment != \"\"%}\n"
"{$mlComment}\n"
"\n"
"{% endif %}\n"
"{$commonHeader()}\n"
"#if !defined({$crcGuardMacro})\n"
"#define {$crcGuardMacro}\n"
"\n"
"#if !defined(ERPC_GENERATED_CRC)\n"
"#define ERPC_GENERATED_CRC {$crc16}\n"
"#else\n"
"#error \"Macro 'ERPC_GENERATED_CRC' shouldn't be defined at this moment.\"\n"
"#endif\n"
"\n"
"#endif // {$crcGuardMacro}\n"
;

