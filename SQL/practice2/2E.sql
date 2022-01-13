

SELECT *  FROM Doctors 
LEFT JOIN PersonalData ON Doctors.PersonalDataID = PersonalData.ID
LEFT JOIN MedicalInsurance ON PersonalData.MedicalInsuranceID = MedicalInsurance.ID;

SELECT *  FROM Patients 
LEFT JOIN PersonalData ON Patients.PersonalDataID = PersonalData.ID
LEFT JOIN Doctors ON Doctors.PersonalDataID = PersonalData.ID
LEFT JOIN MedicalInsurance ON PersonalData.MedicalInsuranceID = MedicalInsurance.ID;


SELECT COUNT(DISTINCT PersonalData.ID)  FROM PersonalData
LEFT JOIN Patients ON Patients.PersonalDataID = PersonalData.ID
LEFT JOIN Doctors ON Doctors.PersonalDataID = PersonalData.ID
LEFT JOIN MedicalInsurance ON PersonalData.MedicalInsuranceID = MedicalInsurance.ID
WHERE (Patients.ID NOT NULL OR Doctors.ID NOT NULL) AND MedicalInsurance.Status = 'active';