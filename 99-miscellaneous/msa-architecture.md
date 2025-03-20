## MSA (Microservice architecture)

### Background
- Traditional deployment method: **monolithic**
  - single deployment
  - prone to spof (single point of failure)
- Transition from monolithic to msa
  - separate domain according to responsibility (srp)
  - however this structure stores data in one common databse, leading to synchronization and coupling issue

### Microservice architecture
- To solve the problem above, each service layer composed its own database repository
  - However this again led to excessive communication amongst service layers
  - HTTP invokes latency issue and restrictions
  - Solution: RPC (remote procedure call) 
    - binary format
    - assures fast speed due to compact data
    - However, tight coupling issue unresolved: synchronous request-response
  - Solution: event-driven architecture (asynchronous)
    - Pub-sub architecture
    - consumers subscribe to events, and when the event is published, it selects to process the event synchronously/asynchronously

### Saga pattern
- In certain services, demand for synchronization amongst service layers still exist 
- To meet these needs, transaction is applied to selected services, and when error occurs, a revert transaction is applied   
- A mediator exists to handle events and transactions 

### CQRS (Command Query Responsibility Segregation)
- Database Optimization
- Certain services have higher usage of create command, others of get queries
- Databses can be distributed according to command/queries so that services can access optimized databases
- Infrastructure optimization resolved

### API Gateway
- Because of the complex backend architecture, clients are unable to directly make requests to targrt services
- API gateway handles client requests and transfers them to proper services, and creates responses 

### Miscellaneous
- Circuit breaker pattern prevents all services going down due to one failure point
- Orchestration (like Kubernetes) is necessary 