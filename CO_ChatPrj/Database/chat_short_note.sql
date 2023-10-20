CREATE DATABASE  IF NOT EXISTS `chat` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `chat`;
-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: chat
-- ------------------------------------------------------
-- Server version	8.1.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `short_note`
--

DROP TABLE IF EXISTS `short_note`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `short_note` (
  `Short_Note_Index` int NOT NULL AUTO_INCREMENT,
  `From_Short_Note_ID` varchar(45) NOT NULL,
  `To_Short_Note_ID` varchar(45) NOT NULL,
  `Respond_Short_Note` int NOT NULL DEFAULT '0',
  `Short_Note_Datetime` datetime NOT NULL,
  `Short_Note_Text` varchar(500) NOT NULL,
  PRIMARY KEY (`Short_Note_Index`),
  KEY `From_Short_Note_ID_idx` (`From_Short_Note_ID`),
  KEY `To_Short_Note_ID_idx` (`To_Short_Note_ID`),
  CONSTRAINT `From_Short_Note_ID` FOREIGN KEY (`From_Short_Note_ID`) REFERENCES `member` (`Member_ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `To_Short_Note_ID` FOREIGN KEY (`To_Short_Note_ID`) REFERENCES `member` (`Member_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `short_note`
--

LOCK TABLES `short_note` WRITE;
/*!40000 ALTER TABLE `short_note` DISABLE KEYS */;
INSERT INTO `short_note` VALUES (2,'jiwon','test',3,'2023-11-11 11:11:11','QnQN'),(3,'soo','test',3,'2020-10-10 00:00:00','졸려요'),(4,'test','jiwon',2,'2011-11-11 11:11:11','화이팅'),(5,'soo','first',1,'2020-10-10 00:00:00','he you!');
/*!40000 ALTER TABLE `short_note` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-10-20 15:59:25
