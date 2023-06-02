package Zadanie2.Helpers;

import java.util.HashMap;
import java.util.Map;

public class InsuranceSystem {
    protected long newUserID =1;
    protected long newAgreementID = 1;    protected Map<Long, User> userMap = new HashMap<Long,User>();
    protected Map<Long, Agreements> agreementsMap = new HashMap<Long, Agreements>();
}
