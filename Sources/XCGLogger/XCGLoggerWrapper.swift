//
//  XCGLoggerWrapper.swift
//  XCGLogger
//
//  Created by Tomas Michalek on 12/12/2017.
//  Copyright © 2017 Cerebral Gardens. All rights reserved.
//

import Foundation

@objc public enum LogLevel: Int {
    case Verbose
    case Debug
    case Info
    case Warning
    case Error
    case Severe
    case None
}

// Obj-C wrapper for XCGLogger
@objcMembers
public class XCGLogWrapper: NSObject {
    public lazy var sharedInstance : XCGLogger = {
        return XCGLogger.default
    }()
    
    public static func log(level: LogLevel, functionName: String, fileName: String, lineNumber: Int, logMessage: String) {
        let log = XCGLogger.default
        let wrapped = XCGLogger.Level(rawValue: level.rawValue) //XCGLogger.LogLevel(rawValue: level.rawValue)
        log.logln(wrapped!, functionName: functionName, fileName: fileName, lineNumber: lineNumber, closure: { () -> String? in
            return logMessage
        })
    }
    
    public static func setup(level: LogLevel = .Debug, showLogIdentifier: Bool = false, showCaller: Bool = true, showThreadName: Bool = true, showLogLevel: Bool = true, showFileNames: Bool = true, showLineNumbers: Bool = true, showDate : Bool = true, writeToFile: String, fileLogLevel: LogLevel, useQueue: DispatchQueue? = nil) {
        let log = XCGLogger.default
        log.setup(level:  XCGLogger.Level(rawValue: level.rawValue)!, showLogIdentifier: showLogIdentifier, showFunctionName: showCaller, showThreadName: showThreadName, showLevel: showLogLevel, showFileNames: showFileNames, showLineNumbers: showLineNumbers, showDate: showDate, writeToFile: writeToFile, fileLevel:  XCGLogger.Level(rawValue: fileLogLevel.rawValue)!)
    }
}
