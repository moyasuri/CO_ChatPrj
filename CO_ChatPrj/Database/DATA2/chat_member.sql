CREATE DATABASE  IF NOT EXISTS `chat` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `chat`;
-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: localhost    Database: chat
-- ------------------------------------------------------
-- Server version	8.0.34

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
-- Table structure for table `member`
--

DROP TABLE IF EXISTS `member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `member` (
  `Member_ID` varchar(45) NOT NULL,
  `Email` varchar(45) NOT NULL,
  `Member_Index` int NOT NULL AUTO_INCREMENT,
  `Phone` varchar(20) NOT NULL,
  `Birth` varchar(20) NOT NULL,
  `Nickname` varchar(20) NOT NULL,
  `Cha_Num` varchar(45) NOT NULL,
  `Member_PW` varchar(45) NOT NULL,
  `Join_Room_Index` int DEFAULT NULL,
  `Name` varchar(45) NOT NULL,
  PRIMARY KEY (`Member_ID`),
  UNIQUE KEY `Member_Index_UNIQUE` (`Member_Index`),
  KEY `Join_Room_idx` (`Join_Room_Index`),
  CONSTRAINT `Join_Room_Index` FOREIGN KEY (`Join_Room_Index`) REFERENCES `room_list` (`Room_Index`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `member`
--

LOCK TABLES `member` WRITE;
/*!40000 ALTER TABLE `member` DISABLE KEYS */;
INSERT INTO `member` VALUES ('asdfsadfasd','asdfsadfsd',6,'333','agasdf','910110','0','',NULL,''),('eeee','eiriaspill@hotmail.com',7,'01049422401','910110','eer','0','',NULL,''),('first','bubu@gmail.com',4,'01000000000','000101','kkkk','32','firstfirst',NULL,''),('jiwon','jiwon@gmail.com',2,'01012345678','991010','JIWONY','2','tjwldnjs00',NULL,'서지원'),('jiwon3','dsf@dfasdf',17,'eeee','910110','haha','72','1234',NULL,'지원'),('s12998','sooya@naver.com',16,'1010102020','991121','SOOYA','72','1234567890',NULL,'수수'),('soo','eunsoo@naver.com',1,'01000001234','981212','EUNSOO','1','whdmstn00',NULL,'조은수'),('soooo','sooya@naver.com',8,'1010102020','991121','SOOYA','72','1234567890',NULL,'수수'),('test','test@naver.com',3,'01098765432','030412','TeSt','2','123',NULL,'abc');
/*!40000 ALTER TABLE `member` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-10-23  0:00:14
