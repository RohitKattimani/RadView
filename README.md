# RadView

# RadView Assessment

**RadView** is a Streamlit-based clinical interface designed to measure **diagnostic decision time and categorical accuracy** in radiological image interpretation tasks.  
The application is intended for **controlled research, evaluation, and experimental use**, not for open or unrestricted deployment.

---

## Overview

RadView presents a sequence of medical images (e.g., MRI scans) to a user and records:

- Binary diagnostic decisions (e.g., *Normal* vs *Tumor*)
- Decision time per case
- Timestamped responses
- Session-level summary statistics

The interface is optimized for **minimal distraction**, **timing precision**, and **clinical-style interaction**, making it suitable for experimental protocols involving radiologists or medical trainees.

---

## Key Features

- Streamlit-based web interface
- Session initialization with countdown
- Randomized case order per session
- Precise response-time tracking
- Clean, clinical UI styling
- Downloadable CSV report of session results
- Stateless restart for repeated assessments

---

## Application Flow

1. **Landing Page**
   - Session overview and instructions

2. **Countdown Phase**
   - Timed countdown before assessment begins

3. **Assessment Session**
   - Sequential image presentation
   - Binary diagnostic choice per image
   - Automatic timing on image load

4. **Results Page**
   - Case-wise response table
   - Average diagnostic time
   - CSV export for downstream analysis

---

## Data Captured

For each case, the following fields are recorded:

- `Image_ID` – Identifier or filename of the image
- `Diagnosis` – User-selected label
- `Time_Seconds` – Decision latency
- `Timestamp` – Time of response

---

## Setup & Execution

### Requirements
- Python 3.8+
- Streamlit
- Pandas

### Install Dependencies
```bash
pip install streamlit pandas
