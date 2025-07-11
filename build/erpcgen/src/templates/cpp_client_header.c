/*
 * AUTOMATICALLY GENERATED FILE - DO NOT EDIT
 */

// Generated from /home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/templates/cpp_client_header.template
extern const char * const kCppClientHeader;

const char * const kCppClientHeader = 
"{% if mlComment != \"\" %}\n"
"{$mlComment}\n"
"\n"
"{% endif %}\n"
"{$commonHeader()}\n"
"\n"
"#if !defined({$clientCppGuardMacro})\n"
"#define {$clientCppGuardMacro}\n"
"\n"
"#include \"{$interfaceCppHeaderName}\"\n"
"\n"
"#include \"erpc_client_manager.h\"\n"
"{$fillNamespaceBegin()>}\n"
"\n"
"{% for iface in group.interfaces %}\n"
"class {$iface.clientClassName}: public {$iface.interfaceClassName}\n"
"{\n"
"    public:\n"
"        {$iface.clientClassName}(erpc::ClientManager *manager);\n"
"\n"
"        virtual ~{$iface.clientClassName}();\n"
"{% for fn in iface.functions if fn.isNonExternalFunction == true %}\n"
"\n"
"{% if fn.mlComment %}\n"
"        {$fn.mlComment}\n"
"{% endif %}\n"
"        virtual {$fn.prototypeInterface};\n"
"{% endfor -- fn %}\n"
"\n"
"    protected:\n"
"        erpc::ClientManager *m_clientManager;\n"
"};\n"
"\n"
"{% endfor -- iface %}\n"
"{$fillNamespaceEnd()}\n"
"#endif // {$clientCppGuardMacro}\n"
;

