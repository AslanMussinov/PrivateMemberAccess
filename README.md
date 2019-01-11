# <p align="center">DISCLAIMER</p>

### <p align="center">I do not endorse the usage of this technique in any production code.</p>
### <p align="center">Use it at your own discretion.</p>

\
\
According to ISO/IEC 14882:2017
>§ 17.8 Template instantiation and specialization\
\
6: The usual ***access checking rules do not apply*** to names in a declaration of an explicit instantiation or explicit
specialization, with the exception of names appearing in a function body, default argument, base-clause,
member-specification, enumerator-list, or static data member or variable template initializer.
[*Note:* In particular, the template arguments and names used in the function declarator (including parameter types,
return types and exception specifications) may be private types or objects that would normally not be accessible.
— *end note*]

it is possible to access private members **outside**\* of a class through *explicit template instantiation*
without the risk of producing undefined behaviour.\
\
\*where **outside** means absence of:
- friend declarations;
- public member accessors/mutators;
- member function templates.
