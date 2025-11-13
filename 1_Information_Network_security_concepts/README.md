# 1. Information and Network security Concepts

#### Key concepts:
- Cybersecurity, information security and network security
- OSI security architecture
- Security attacks, services and mechanisms
- Cryptography
- Network security
- Trust and Trustworthiness

### Cybersecurity, Info security and Network security
**List and define the key objectives of computer security:**  
The fundamental security objectives are referred as *CIA triad*, defined as:
- Confidentiality: assure that private information is *not available* or disclosed to *unauthorized individuals*
- Integrity: referred to data assures that data and programs are *changed only* in specified and authorized manner, when referred to systems assures that a system performs its intended function in an unimpaired manner
- Availability: assure that the system and services *work properly* to authorized users

To present the complete picture we must introduce:
- Authenticity: Is the property of being able *to be verified and trusted*
- Accountability: generates the requirement for actions of an entity to be *traced uniquely to that entity*

**Provide the definition of Cybersecurity, information & network security:**  
Cybersecurity is the protection of information stored, transmitted and processed in any electronic device  

As subset of cybersecurity we can define:
- Information Security: is the preservation of confidentiality, integrity and availability of information
- Network security: is the protection of networks and their service

### OSI security architecture
**What is the OSI security architecture?**   
Is a *systematic approach* to define the *requirements* for security and characterizing the approaches to satisfy those requirements. It also defines:
- *Security attack*: any action that compromises the security of information owned by an organization
- *Threat*: any event with the potential to impact negatively the organization operations
- *Attack*: any malicious activity that attempts to perform a malicious action to information systems resources or the information itself

### Security attacks, Security services and mechanisms
**How can we classify security attacks?**  
- *Passive attacks*: is any attempt to learn or make use of information from the system without affecting the system resources. Two types of passive are the release of message contents and traffic analysis
- *Active attacks*: they involve some modification of the data stream or the creation of a false stream, the main categories are:
    - *Masquerade* is when one entity pretends to be a different entity
    - *Replay* involves the passive capture of data and its subsequent retransmission
    - *Data modification* when some portion of a legitimate message is altered
    - *Denial of service* prevents the normal use of communication facilities

**List and define categories of security services:**  
A security service is a capability that supports one or more of the security requirements (CIAAA), they implement security policies and are implemented by security mechanisms, the most important are:
- *Authentication* service is concerned with assuring that a communication is authentic, by assuring that the two entities involved are authentic and that the connection is not interfered
- *Access Control* is the ability to limit and control the access to host systems and application via communications links
- *Data Confidentiality* is the protection of transmitted data from passive attacks
- *Data integrity* assures that the messages are received as sent, the destruction is also covered under this service
- *Non-repudiation* prevents either sender or receiver from denying a transmitted message
- *Availability service* is one that protect a system to ensure its availability

**List and briefly define categories of security mechanisms:**  
*Security mechanism* are processes used to detect, prevent or recover from a security attach 
- *Cryptographic algorithms* we can distinguish between reversible (E and D) and irreversible (only E) cryptographic mechanisms
- *Data integrity* are a variety of mechanisms used to be assure the integrity of a data unit or streams of data unit
- *Digital signature* data append to, or a cryptographic transformation of, a data unit that allow a recipient of the data to prove the source and integrity of the data sent 
- *Authentication exchange* used to ensure the identity of an entity by means of information exchange
- *Traffic padding* the insertion of bits into gaps in a data stream to frustrate traffic analysis attempts
- *Routing control* enable selection of a particular secure routes for certain data and allows routing changes
- *Notarization* is the use of a third party to assure certain properties of a data exchange
- *Access control* a variety of mechanism that enforce access rights to resources

### Cryptography
**Provide an overview of the three types of cryptographic algorithms:**  
Cryptography is a branch of mathematics that deals with the transformation of data, cryptographic algorithms can be divided into three categories:
- *Keyless* because they do not use any keys during cryptographic transformations
- *Single-key* the result of a transformation is a function of the input data and a single key
- *Two-key* where two different but related keys are used at various stages of a calculation (private and public key)

### Network security
**Provide an overview of the two major elements of network security:**   
Network security is a term that comprehends the security of the *communication pathways* of the network and the security of *network devices* and devices attached to the network  
The communication security is primarily implemented using network protocols  
The device security is enforced primarily with three types of device:
- *Firewall* is a S and/or H capability that limits the access access between network and devices attached to the network, using a set of rules based on traffic content and/or traffic pattern
- *IDS*: H or S products that gather and analyze information from the network to find and provide real-time warning of unauthorized attempts to access system resources 
- *IPS*: H or S products designed to detect intrusive activity and attempt to stop it before it reaches the target

### Trust and trustworthiness
**Briefly explain the concepts of trust and trustworthiness:**  
Trust is the willingness of a party to be vulnerable to the actions of another party based on the expectations that the other will perform actions important to the truster  
Trustworthiness is a characteristic of an entity that reflects the degree to which that entity is deserving of trust
