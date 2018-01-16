//
//  ContentfulClient.hpp
//  Contentful.cpp
//
//  Created by Oliver Hookins on 16.01.18.
//  Copyright © 2018 Oliver Hookins. All rights reserved.
//

#ifndef ContentfulClient_hpp
#define ContentfulClient_hpp

#include <string>
#include <curl/curl.h>

class ContentfulClient {
public:
    // Creates the client with the CDA token for access
    ContentfulClient(std::string TokenToSet);
    
    // Gets all entries from a given space
    void GetEntries(std::string Space);
    
private:
    // Internal Curl handle pointer and userdata area for http requests
    CURL* CurlHandle = nullptr;
    
    // Curl data
    FILE* HeaderData;
    FILE* BodyData;
    char ErrorData[CURL_ERROR_SIZE];
    
    // CDA token
    std::string Token = "";
    
    // CDA root
    const std::string CDA = "https://cdn.contentful.com";
};

#endif /* ContentfulClient_hpp */
