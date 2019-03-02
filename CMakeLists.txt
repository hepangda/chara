cmake_minimum_required(VERSION 3.0)
project(chara)

set(CMAKE_CXX_STANDARD 14)
link_libraries(pthread)
add_definitions("-g")

aux_source_directory(src/core SOURCE_CORE)
aux_source_directory(src/protocol SOURCE_PROTOCOL)
aux_source_directory(src/utils SOURCE_UTILS)


add_executable(chara
        src/chara.cc
        ${SOURCE_CORE}
        ${SOURCE_PROTOCOL}
        ${SOURCE_UTILS} src/protocol/dns_resolver.cc src/protocol/dns_resolver.h src/protocol/dns_resolver.cc src/protocol/dns_resolver.h src/protocol/dns_packet.cc src/protocol/dns_packet.h src/protocol/dns_query.cc src/protocol/dns_query.h src/protocol/dns_domain_name.cc src/protocol/dns_domain_name.h src/utils/net_assist.h src/utils/test_assist.h src/protocol/dns_header.cc src/protocol/dns_header.h src/protocol/dns_resource_record.cc src/protocol/dns_resource_record.h src/protocol/dns_rdata.cc src/protocol/dns_rdata.h)