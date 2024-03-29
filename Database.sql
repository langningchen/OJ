CREATE TABLE IF NOT EXISTS `EmailVerificationCodes` (
    `EmailAddress` VARCHAR(64) NOT NULL UNIQUE,
    `VerificationCode` VARCHAR(32) NOT NULL,
    `CreateTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE IF NOT EXISTS `Files` (
    `FID` INT NOT NULL AUTO_INCREMENT PRIMARY KEY UNIQUE,
    `UID` INT NOT NULL,
    `Filename` TEXT NOT NULL,
    `FileType` TEXT NOT NULL,
    `FileToken` VARCHAR(32) NOT NULL UNIQUE,
    `CreateTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE IF NOT EXISTS `Passkeys` (
    `UID` INT UNSIGNED NOT NULL,
    `Credential` TEXT NOT NULL,
    `PublicKey` TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS `PasskeyChallenges` (
    `Challenge` VARCHAR(64) NOT NULL PRIMARY KEY UNIQUE,
    `CreateTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE IF NOT EXISTS `Problems` (
    `PID` INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY UNIQUE,
    `Title` VARCHAR(32) NOT NULL UNIQUE,
    `IOFilename` TEXT NOT NULL,
    `Description` TEXT NOT NULL,
    `Input` TEXT,
    `Output` TEXT NOT NULL,
    `Range` TEXT,
    `Hint` TEXT,
    `Samples` TEXT,
    `TestGroups` TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS `Settings` (
    `Key` VARCHAR(32) NOT NULL UNIQUE,
    `Value` TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS `Submissions` (
    `SID` INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY UNIQUE,
    `PID` INT UNSIGNED NOT NULL,
    `UID` INT UNSIGNED NOT NULL,
    `Code` TEXT NOT NULL,
    `Result` INT UNSIGNED NOT NULL DEFAULT '0',
    `Description` TEXT,
    `Time` INT UNSIGNED NOT NULL DEFAULT '0',
    `TimeSum` INT UNSIGNED NOT NULL DEFAULT '0',
    `Memory` INT UNSIGNED NOT NULL DEFAULT '0',
    `Score` INT UNSIGNED NOT NULL DEFAULT '0',
    `EnableO2` tinyint(1) NOT NULL DEFAULT '0',
    `TestGroups` TEXT,
    `CreateTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE IF NOT EXISTS `Tokens` (
    `TID` INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY UNIQUE,
    `TokenValue` VARCHAR(32) NOT NULL UNIQUE,
    `UID` INT UNSIGNED NOT NULL,
    `CreateTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE IF NOT EXISTS `Users` (
    `UID` INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY UNIQUE,
    `Username` VARCHAR(32) NOT NULL UNIQUE,
    `Password` VARCHAR(64) NOT NULL,
    `Nickname` VARCHAR(32) NOT NULL,
    `EmailAddress` TEXT NOT NULL,
    `Role` INT UNSIGNED NOT NULL
);
CREATE TABLE IF NOT EXISTS `TempTestData` (
    `Index` VARCHAR(32) NOT NULL PRIMARY KEY UNIQUE,
    `Data` TEXT NOT NULL
);