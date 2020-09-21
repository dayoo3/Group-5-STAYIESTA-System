-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 17, 2020 at 04:05 PM
-- Server version: 10.4.13-MariaDB
-- PHP Version: 7.2.32

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `arrobadb`
--

-- --------------------------------------------------------

--
-- Table structure for table `booking`
--

CREATE TABLE `booking` (
  `bookingID` varchar(255) NOT NULL,
  `bookingDayInit` int(11) DEFAULT NULL,
  `bookingMthInit` int(11) DEFAULT NULL,
  `bookingYrInit` int(11) DEFAULT NULL,
  `bookingDayFinal` int(11) DEFAULT NULL,
  `bookingMthFinal` int(11) DEFAULT NULL,
  `bookingYrFinal` int(11) DEFAULT NULL,
  `paymentStatus` varchar(255) DEFAULT NULL,
  `reviewStatus` varchar(255) DEFAULT NULL,
  `userID` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `booking`
--

INSERT INTO `booking` (`bookingID`, `bookingDayInit`, `bookingMthInit`, `bookingYrInit`, `bookingDayFinal`, `bookingMthFinal`, `bookingYrFinal`, `paymentStatus`, `reviewStatus`, `userID`) VALUES
('B00001', 1, 1, 2019, 31, 1, 2019, 'Y', 'Y', 'C32269'),
('B00002', 1, 2, 2019, 28, 2, 2019, 'N', 'N', 'C32269'),
('B00003', 1, 3, 2019, 31, 3, 2019, 'Y', 'Y', 'C32269'),
('B66826', 10, 12, 2019, 1, 1, 2020, 'N', 'N', 'C32269'),
('DUMMY', NULL, NULL, NULL, NULL, NULL, NULL, 'N', 'N', 'DUMMYUSER');

--
-- Triggers `booking`
--
DELIMITER $$
CREATE TRIGGER `aft_booking_delete` BEFORE DELETE ON `booking` FOR EACH ROW UPDATE homestay 
SET bookingID = NULL
WHERE bookingID = OLD.bookingID
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `homestay`
--

CREATE TABLE `homestay` (
  `homestayID` varchar(255) NOT NULL,
  `homestayName` varchar(255) DEFAULT NULL,
  `homestayLoc` varchar(255) DEFAULT NULL,
  `homestayType` varchar(255) DEFAULT NULL,
  `homestayBedrmNum` int(11) DEFAULT NULL,
  `homestayBathrmNum` int(11) DEFAULT NULL,
  `homestayPrice` int(11) DEFAULT NULL,
  `carparkNum` int(11) DEFAULT NULL,
  `wifi` varchar(255) DEFAULT NULL,
  `nonSmoking` varchar(255) DEFAULT NULL,
  `userID` varchar(255) NOT NULL,
  `bookingID` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `homestay`
--

INSERT INTO `homestay` (`homestayID`, `homestayName`, `homestayLoc`, `homestayType`, `homestayBedrmNum`, `homestayBathrmNum`, `homestayPrice`, `carparkNum`, `wifi`, `nonSmoking`, `userID`, `bookingID`) VALUES
('DUMMY', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'DUMMYHOST', 'DUMMY'),
('S21525', 'Mutiara Ville', 'Cyberjaya', 'Apartment', 2, 3, 150, 1, 'Y', 'N', 'H74532', 'B66826'),
('S33542', 'Suria Homes', 'Shah Alam', 'Villa', 3, 2, 350, 2, 'Y', 'N', 'H74532', 'B00003'),
('S60320', 'Melati Complex', 'Cyberjaya', 'Service Apartment', 3, 2, 220, 2, 'N', 'Y', 'H74532', 'B00001'),
('S73893', 'Viva Complex', 'Putrajaya', 'Apartment', 2, 2, 300, 1, 'Y', 'Y', 'H74532', 'B00002'),
('S93300', 'Seasons Garden', 'Kuala Lumpur', 'Apartment', 3, 2, 180, 1, 'Y', 'N', 'H74532', NULL);

--
-- Triggers `homestay`
--
DELIMITER $$
CREATE TRIGGER `aft_homestay_delete` BEFORE DELETE ON `homestay` FOR EACH ROW DELETE FROM booking
WHERE booking.bookingID = OLD.bookingID
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `payment`
--

CREATE TABLE `payment` (
  `paymentID` varchar(255) NOT NULL,
  `paymentAmount` int(11) DEFAULT NULL,
  `paymentDay` int(11) DEFAULT NULL,
  `paymentMth` int(11) DEFAULT NULL,
  `paymentYr` int(11) DEFAULT NULL,
  `cardName` varchar(255) DEFAULT NULL,
  `cardNum` varchar(255) DEFAULT NULL,
  `userID` varchar(255) NOT NULL,
  `bookingID` varchar(255) NOT NULL,
  `rewardID` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `payment`
--

INSERT INTO `payment` (`paymentID`, `paymentAmount`, `paymentDay`, `paymentMth`, `paymentYr`, `cardName`, `cardNum`, `userID`, `bookingID`, `rewardID`) VALUES
('DUMMY', NULL, NULL, NULL, NULL, NULL, NULL, 'DUMMYUSER', 'DUMMY', NULL),
('P97617', 120, 2, 10, 2019, 'Fabash', '1234567812345678', 'C32269', 'B66826', 'DQ8U');

-- --------------------------------------------------------

--
-- Table structure for table `review`
--

CREATE TABLE `review` (
  `reviewID` varchar(255) NOT NULL,
  `reviewRate` int(11) DEFAULT NULL,
  `reviewDesc` varchar(255) DEFAULT NULL,
  `reviewDay` int(11) DEFAULT NULL,
  `reviewMth` int(11) DEFAULT NULL,
  `reviewYr` int(11) DEFAULT NULL,
  `userID` varchar(255) NOT NULL,
  `bookingID` varchar(255) NOT NULL,
  `homestayID` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `reward`
--

CREATE TABLE `reward` (
  `rewardID` varchar(255) NOT NULL,
  `rewardDesc` varchar(255) DEFAULT NULL,
  `rewardValidDay` int(11) DEFAULT NULL,
  `rewardValidMth` int(11) DEFAULT NULL,
  `rewardValidYr` int(11) DEFAULT NULL,
  `discountType` int(11) DEFAULT NULL,
  `discountRate` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `reward`
--

INSERT INTO `reward` (`rewardID`, `rewardDesc`, `rewardValidDay`, `rewardValidMth`, `rewardValidYr`, `discountType`, `discountRate`) VALUES
('DeZSIc', 'Enjoy your reward!', 0, 0, 0, 0, 10),
('DQ8U', 'Welcome to Stayiesta! Enjoy an RM20 off on any of your next Stay-iesta!', 31, 12, 2023, 0, 30),
('DUMMY', NULL, NULL, NULL, NULL, NULL, NULL),
('F08J', 'For customers reaching a total of 5 bookings. Get a 5% discount on booking price! (Consumed once used)', 16, 10, 2019, 0, 5),
('R076', 'Happy anniversary to Stayiesta! Enjoy a 10% off on your next Stay-iesta', 31, 1, 2020, 0, 10);

--
-- Triggers `reward`
--
DELIMITER $$
CREATE TRIGGER `aft_reward_delete` BEFORE DELETE ON `reward` FOR EACH ROW DELETE FROM user_reward
WHERE rewardID = OLD.rewardID
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `ticket`
--

CREATE TABLE `ticket` (
  `ticketID` varchar(255) NOT NULL,
  `ticketType` varchar(255) DEFAULT NULL,
  `ticketTitle` varchar(255) DEFAULT NULL,
  `ticketDesc` varchar(255) DEFAULT NULL,
  `ticketDay` int(11) DEFAULT NULL,
  `ticketMth` int(11) DEFAULT NULL,
  `ticketYr` int(11) DEFAULT NULL,
  `userID` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `userID` varchar(255) NOT NULL,
  `userFirstName` varchar(255) DEFAULT NULL,
  `userLastName` varchar(255) DEFAULT NULL,
  `username` varchar(255) DEFAULT NULL,
  `userPassword` varchar(255) DEFAULT NULL,
  `userPhoneNum` varchar(255) DEFAULT NULL,
  `userEmail` varchar(255) DEFAULT NULL,
  `accType` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`userID`, `userFirstName`, `userLastName`, `username`, `userPassword`, `userPhoneNum`, `userEmail`, `accType`) VALUES
('C17660', 'hey', 'hey', 'hey', 'hey', 'hey', 'hey', 2),
('C276150796', 'Temporary', 'User', 'malik', 'mlikr', '1234', 'malik@malik', 2),
('C32269', 'Faris', 'Bashir', 'fabash_', 'abc123', '0148899956', 'farisbashirr@gmail.com', 2),
('C578', 'test', 'test', 'test', 'test', 'test', 'test', 2),
('DUMMYHOST', 'DUMMY', 'DUMMY', 'DUMMYHOST', 'debug', 'DUMMY', 'DUMMY', 1),
('DUMMYUSER', 'DUMMY', 'DUMMY', 'DUMMYUSER', 'debug', 'DUMMY', 'DUMMY', 2),
('H74532', 'host', 'host', 'host', 'host', 'host', 'host', 1),
('T0', NULL, NULL, 'admin', 'admin123', 'test', 'test', 3);

--
-- Triggers `users`
--
DELIMITER $$
CREATE TRIGGER `aft_user_delete1` BEFORE DELETE ON `users` FOR EACH ROW DELETE FROM homestay
WHERE homestay.userID = OLD.userID
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `aft_user_delete2` BEFORE DELETE ON `users` FOR EACH ROW DELETE FROM booking
WHERE booking.userID = OLD.userID
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `aft_user_delete_3` BEFORE DELETE ON `users` FOR EACH ROW DELETE FROM user_reward
WHERE user_reward.userID = OLD.userID
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `aft_user_insert` AFTER INSERT ON `users` FOR EACH ROW INSERT INTO user_reward VALUES (NEW.userID,'DQ8U','N')
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `user_reward`
--

CREATE TABLE `user_reward` (
  `userID` varchar(255) NOT NULL,
  `rewardID` varchar(255) NOT NULL,
  `isUsed` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user_reward`
--

INSERT INTO `user_reward` (`userID`, `rewardID`, `isUsed`) VALUES
('C17660', 'DQ8U', 'N'),
('C32269', 'DQ8U', 'Y'),
('C32269', 'F08J', 'Y'),
('C32269', 'R076', 'N'),
('DUMMYUSER', 'R076', 'N');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `booking`
--
ALTER TABLE `booking`
  ADD PRIMARY KEY (`bookingID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `homestay`
--
ALTER TABLE `homestay`
  ADD PRIMARY KEY (`homestayID`),
  ADD KEY `userID` (`userID`),
  ADD KEY `bookingID` (`bookingID`);

--
-- Indexes for table `payment`
--
ALTER TABLE `payment`
  ADD PRIMARY KEY (`paymentID`),
  ADD KEY `rewardID` (`rewardID`),
  ADD KEY `bookingID` (`bookingID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `review`
--
ALTER TABLE `review`
  ADD PRIMARY KEY (`reviewID`),
  ADD KEY `userID` (`userID`),
  ADD KEY `bookingID` (`bookingID`);

--
-- Indexes for table `reward`
--
ALTER TABLE `reward`
  ADD PRIMARY KEY (`rewardID`);

--
-- Indexes for table `ticket`
--
ALTER TABLE `ticket`
  ADD PRIMARY KEY (`ticketID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`userID`);

--
-- Indexes for table `user_reward`
--
ALTER TABLE `user_reward`
  ADD PRIMARY KEY (`userID`,`rewardID`),
  ADD KEY `rewardID` (`rewardID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `booking`
--
ALTER TABLE `booking`
  ADD CONSTRAINT `booking_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `users` (`userID`);

--
-- Constraints for table `homestay`
--
ALTER TABLE `homestay`
  ADD CONSTRAINT `homestay_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `users` (`userID`),
  ADD CONSTRAINT `homestay_ibfk_2` FOREIGN KEY (`bookingID`) REFERENCES `booking` (`bookingID`);

--
-- Constraints for table `payment`
--
ALTER TABLE `payment`
  ADD CONSTRAINT `payment_ibfk_1` FOREIGN KEY (`rewardID`) REFERENCES `reward` (`rewardID`),
  ADD CONSTRAINT `payment_ibfk_2` FOREIGN KEY (`bookingID`) REFERENCES `booking` (`bookingID`),
  ADD CONSTRAINT `payment_ibfk_3` FOREIGN KEY (`userID`) REFERENCES `users` (`userID`);

--
-- Constraints for table `review`
--
ALTER TABLE `review`
  ADD CONSTRAINT `review_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `users` (`userID`),
  ADD CONSTRAINT `review_ibfk_2` FOREIGN KEY (`bookingID`) REFERENCES `booking` (`bookingID`);

--
-- Constraints for table `ticket`
--
ALTER TABLE `ticket`
  ADD CONSTRAINT `ticket_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `users` (`userID`);

--
-- Constraints for table `user_reward`
--
ALTER TABLE `user_reward`
  ADD CONSTRAINT `user_reward_ibfk_1` FOREIGN KEY (`rewardID`) REFERENCES `reward` (`rewardID`),
  ADD CONSTRAINT `user_reward_ibfk_2` FOREIGN KEY (`userID`) REFERENCES `users` (`userID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
