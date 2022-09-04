/**
 * @author ByaCherX
 * @copyright RedDevSoftware
 */
// @ts-check

interface Inf {
  title: string;
}

type Inf_r = "str" | "str1";


type ReqType = {
  transactionId: string,
  chain: {
    title: string,
    linker: number,
  },
  pay_method: {
    cardToken: string
  },
};

type cardType = ReqType['pay_method']

function getPayment(): ReqType['pay_method'] {
  return {
    cardToken: '8cq3asc2r48wc8cv1b00a456c000'
  }
}



