//
//  XCGLogger.h
//  XCGLogger: https://github.com/DaveWoodCom/XCGLogger
//
//  Created by Dave Wood on 2014-06-06.
//  Copyright (c) 2014 Dave Wood, Cerebral Gardens.
//  Some rights reserved: https://github.com/DaveWoodCom/XCGLogger/blob/master/LICENSE.txt
//

#import <Cocoa/Cocoa.h>

#ifdef __OBJC__
//log(level: LogLevel, functionName: String, fileName: String, lineNumber: Int, logMessage: String)
#define XCGLogva(level, message) [XCGLogWrapper logWithLevel:level functionName: @(__PRETTY_FUNCTION__) fileName: @__FILE__ lineNumber: __LINE__ logMessage: message ]
#define XCGLog(level, ...) XCGLogva(level, ([NSString stringWithFormat: __VA_ARGS__ ]) )

#define LogTrace(...) XCGLogva( LogLevelDebug, ([NSString stringWithFormat: __VA_ARGS__ ]) )
#define LogInfo(...)  XCGLogva( LogLevelInfo, ([NSString stringWithFormat: __VA_ARGS__ ]) )
#define LogWarn(...)  XCGLogva( LogLevelWarning, ([NSString stringWithFormat: __VA_ARGS__ ]) )
#define LogError(...) XCGLogva( LogLevelError, ([NSString stringWithFormat: __VA_ARGS__ ]) )

#define LogLevel(level) [XCGLogWrapper setLevel:level]

#ifdef DEBUG

#define LogSetup(file,level) [XCGLogWrapper setupWithLevel:level                \
                      showLogIdentifier:NO                                      \
                             showCaller:YES                                     \
                         showThreadName:YES                                     \
                           showLogLevel:YES                                     \
                          showFileNames:YES                                     \
                        showLineNumbers:YES                                     \
                               showDate:YES                                     \
                            writeToFile:file                                    \
                           fileLogLevel:level                                   \
                               useQueue:nil ]
#else
#define LogSetup(file,level) [XCGLogWrapper setupWithLevel:level                \
                           showLogIdentifier:NO                                 \
                                  showCaller:NO                                 \
                              showThreadName:NO                                 \
                                showLogLevel:YES                                \
                               showFileNames:NO                                 \
                             showLineNumbers:NO                                 \
                                    showDate:YES                                \
                                 writeToFile:file                               \
                                fileLogLevel:level                              \
                                    useQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0) ]

#endif

#endif

//! Project version number for XCGLogger.
FOUNDATION_EXPORT double XCGLoggerVersionNumber;

//! Project version string for XCGLogger.
FOUNDATION_EXPORT const unsigned char XCGLoggerVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <XCGLogger/PublicHeader.h>

